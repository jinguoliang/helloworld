#!/bin/bash
base_tag="M8960AAAAANLYA2203"
work_space=`pwd`
git_list_file="gitlist.txt"
manifest_file=".repo/manifest.xml"
branchName=""
report_file="${work_space}/diff_patch_list.txt"
currentBranch=""
findTag=""
tagOld="" #git tag in the 1st branch
tagNew="" #git tag in the 2nd branch
patch_dir="Deliver_To_CCI_patches"

function gettagdiff(){
if [ -s $report_file  ]; then
    echo "">$report_file
fi
if [ -s $manifest_file  ]; then
    mainrevision=`cat $manifest_file |grep "default remote"|sed 's/^.*revision="//'|sed 's/"\/>//'`
    echo -e "\033[44mmaster branch is $mainrevision\033[m"
else
    bail "$manifest_file not exist, exit..."
fi

if [ -s $git_list_file  ]; then
    gits=(`cat $git_list_file`)
else
    bail "$git_list_file not exist, exit..."
fi

for f in ${gits[*]}
do
    if [ $f != "" ]; then
        echo -e "\033[42mprocessing git: $f\033[m"
        echo "*******************diffpatch for git: $f *******************">>$report_file
        cd $f
        findTag=`git tag|grep $base_tag`
        if [ "$findTag" = "" ]; then
            echo -e "\033[41mTag: $base_tag is not found in current git.\033[m"
            echo "$base_tag is not found in git:$f">>$report_file
        else
        getCurrentBranch
        git log --reverse --no-merges --oneline $base_tag..$currentBranch| sed 's/^/p /' >>$report_file
        fi
        cd $work_space
    fi
done
}

#get the latest branch revision for the given git.
#$1 git name
#$2 manifest file
#$3 tag args
#$4 main revison, default branch.
function getLatestBranch() 
{
fullGitName="\"$1\""
cat $2 | grep -q $fullGitName
if [ $? -eq 0 ]; then
    if [ "$3" == "old" ]; then
        tagOld=`grep  $fullGitName $2|grep revision|grep -o -e 'revision="\S*"'| grep -o -e '"\S*'| sed 's:"::'|sed 's:"::'`
        if [ "$tagOld" = "" ]; then
            tagOld=$4
        fi
        echo -e "\033[46mOld tag is $tagOld\033[m"
    elif [ "$3" == "new" ]; then
        tagNew=`grep  $fullGitName $2|grep revision|grep -o -e 'revision="\S*"'| grep -o -e '"\S*'| sed 's:"::'|sed 's:"::'`
        if [ "$tagNew" = "" ]; then
            tagNew=$4
        fi
        echo -e "\033[46mNew tag is $tagNew\033[m"
    fi
else
    bail "\033[41m$fullGitName is not included in the $2..."
fi
}

#error handler, print information and exit.
#$* error information
function bail(){
echo -e "\033[41m##########################################\033[m"
echo -e "\033[41m$*\033[m"
echo -e "\033[41m##########################################\033[m"
return 1
}

#get current brach name
function getCurrentBranch(){
if [ -d .git ];then 
    currentBranch=`git branch -r|grep "\->\ "|sed 's/^.*\->\ //'`
    echo original branch is: $currentBranch
else
    bail ".git doesn't exit, please check current path: `pwd`"
fi
}

#find out diff branch between two SW versions
#$1:the first SW version, should be the earlier version.
#$2:the second SW version,should be the later version.

function getversiondiff(){
getSaticManifest $1
getSaticManifest $2
getfilediff ${1}_manifest_static.xml ${2}_manifest_static.xml
}


#find out diff patch from two input manifest.xml
#$1:the 1st manifest.xml, should be the earlier version.
#$2:the 2nd manifest.xml,should be the later version.
function getfilediff(){

if [ ! -f $1 ]; then
    bail "$1 is not exist, please check again!"
elif [ ! -f $2 ]; then 
    bail "$2 is not exist, please check again!"
fi

versionBranchOld=`cat $1 |grep "default remote"|sed 's/^.*revision="//'|sed 's/".*//'`
versionBranchNew=`cat $2 |grep "default remote"|sed 's/^.*revision="//'|sed 's/".*//'`
if [ "$versionBranch1" != "$versionBranch2" ]; then 
    bail "these two branches were not at the same main branch, so are you kidding me?"
fi

#####!!!!!!!!!!!!changed############
cur_branch="kk-amur-jasmine-arima-somc"
#diff $1 $2|grep -o -e 'path="\S*'| grep -o -e '"\S*'| sed 's:"::'|sed 's:"::'|uniq>$git_list_file
cat $2|grep upstream=$cur_branch|grep -o -e 'path="\S*'| grep -o -e '"\S*'| sed 's:"::'|sed 's:"::'>$git_list_file
# echo "device/qcom/common">>$git_list_file
# echo "device/cci/eagle_ds">>$git_list_file
# echo "device/cci/eagle_lte">>$git_list_file
# echo "device/cci/eagle_ss">>$git_list_file

if [ -f $report_file  ]; then
    echo "">$report_file
fi

if [ -f $git_list_file  ]; then
    gits=(`cat $git_list_file`)
else
    bail "$git_list_file not exist, exit..."
fi

for f in ${gits[*]}
do
    if [ $f != "" ]; then
        echo -e "\033[42mprocessing git: $f\033[m"
        echo "-->diffpatch for git: $f">>$report_file
        getLatestBranch $f $1 "old" $versionBranchOld
        getLatestBranch $f $2 "new" $versionBranchNew
        if [ -d $f ]; then 
            cd $f
            findTag=`git log|grep $tagOld`
            existspatch="false"
            if [ "$findTag" = "" ]; then
                echo -e "\033[41mTag: $tagOld is not found in $2.\033[m"
                echo "$tagOld is not found in git:$f">>$report_file
            else
                if [ "$tagOld" != "$tagNew" ]; then
                     
                     #git log --reverse --no-merges --oneline $tagOld..$tagNew|sed 's/^/p /'|sed "s#^#$f\t#">>$report_file
                     gitlogdiffs=(`git log --reverse --no-merges --pretty=format:"%H:-:%ce" $tagOld..$tagNew`)
                     len=${#gitlogdiffs[@]}
                     rm *.patch
                     for((i=0;i<len;i++));do    #create patch files
                          #echo ${gitlogdiffs[i]}|sed 's/:-:/ /' >>$report_file
                          subgitlog=(`echo ${gitlogdiffs[i]}|sed 's/:-:/ /'`)
                          if [[ ${subgitlog[1]} == *@sonymobile.com || ${subgitlog[1]} == *@cnbjlnx*.corpusers.net ]];then
                               #echo "SHA1="${subgitlog[0]}" author="${subgitlog[1]}>>$report_file
                               getpatchOld=`git format-patch -1 ${subgitlog[0]}`
                               getpatchNew=`ls $getpatchOld  |sed "s/^[0-9]\{1,10\}-/DD${i}-/"`
                               mv $getpatchOld $getpatchNew
                               echo $getpatchNew>>$report_file
                               if [ "$existspatch" = "false" ];then
                                   existspatch="true"
                               fi
                          fi
                     done
                fi
            fi
            cd $work_space
            #echo "$f/*.patch"
            #copy patch files
            if [ "$existspatch" = "true" ];then
                cp $f/*.patch $patch_dir --parents
                rm $f/*.patch
            fi
        else
            bail "$f doesn't exist, please check"
        fi
    fi
done
}

function getSaticManifest(){
repository getpackage build-metadata $1 1>/dev/null
dpkg -x build-metadata_${1}_all.deb .
mv manifest_static.xml ${1}_manifest_static.xml
rm build-metadata_${1}_all.deb releasable-packages.txt
}



##########
#main 
##########

function my_main(){
  if [ ! -s $patch_dir ];then
       mkdir $patch_dir
  else
       rm -rf $patch_dir/*
  fi
  getfilediff $1 $2 
}

my_main "$@"
