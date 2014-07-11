#!/bin/bash

FILE_NAME=`date +%Y%m%d%H%M`_rebase.xml
DIFF_FILE=diff_file_reabse.txt
IS_EAGLE_GIT=""
#TEMP_FILE=temp_file.txt
DIFF_GITS=""
WORK_SPACE=`pwd`
REBASE_LOG=$WORK_SPACE"/"`date +%Y%m%d%H%M`_rebase.log

cur_branch="kk-amur-jasmine-arima-somc"



#error handler, print information
 #$* error information
function bail(){
	echo -e "\033[41m##########################################\033[m"
	echo -e "\033[41m$*\033[m"
	echo -e "\033[41m##########################################\033[m"
	return 1
}

#find the files that may have conflicts
#in: 		current_manefest old new
#out:  		DIFF_FILE
function findDiffFiles(){
   branchout_gits=(`grep "$cur_branch" $1 |grep -o -e 'name="\S*'`)
   release_update_gits=(`diff $2 $3| sort -u | grep -o -e 'name="\S*' |uniq`)

   if [ ${#branchout_gits[@]} = 0 ]; then
      bail "there is no E1_II gits in $1"
   fi

   if [ ${#release_update_gits[@]} = 0 ]; then
       bail "there is no diff between two version!"
   fi

   for((i=0;i<${#release_update_gits[@]};i++));do
     for((j=0;j<${#branchout_gits[@]};j++));do

        if [ ${release_update_gits[i]} == ${branchout_gits[j]} ];then
              temp_value=`grep ${release_update_gits[i]} $2|grep "path="`
              if [ "$temp_value" = "" ];then
                  grep ''${release_update_gits[i]}'' $2 |grep -o -e 'name="\S*' |grep -o -e '"\S*' |sed 's/"//' |sed 's/"//' >>$DIFF_FILE
              else
                  grep ''${release_update_gits[i]}'' $2 |grep -o -e 'path="\S*' |grep -o -e '"\S*' |sed 's/"//' |sed 's/"//' >>$DIFF_FILE
              fi
              break
         fi
     done
   done
}

#rebase the diff gits
#in: file: DIFF_FILE
function exec_rebase(){
	if [ ! -f $DIFF_FILE ];then
		bail "$DIFF_FILE is not exists."
	fi

	DIFF_GITS=(`cat $DIFF_FILE`)

	echo "begin to rebase codebase ..." |tee >>$REBASE_LOG
	for((i=0;i<${#DIFF_GITS[@]};i++));do
	   cd ${DIFF_GITS[i]}
	   echo "==========Rebase==${DIFF_GITS[i]}=====begin==========================================="
	   echo "==========Rebase==${DIFF_GITS[i]}=====begin===========================================" |tee >>$REBASE_LOG
	   git fetch --all |tee >>$REBASE_LOG
	   git merge --no-ff origin/amur-jasmine-arima-release |tee >>$REBASE_LOG
	   echo "==========Rebase==${DIFF_GITS[i]}=====End===========================================" |tee >>$REBASE_LOG
	   echo "==========Rebase==${DIFF_GITS[i]}=====End==========================================="
	   cd -
	done

	echo "end merge codebase ...">>$REBASE_LOG
}


function exec_repo_upload(){
	if [ ! -f $DIFF_FILE ];then
		bail "$DIFF_FILE is not exists."
	fi

#repo start kk-yukonodm-eagle-tina-somc --all

	DIFF_GITS=(`cat $DIFF_FILE`)

	echo "begin to repo upload ...">>$REBASE_LOG
	for((i=0;i<${DIFF_GITS[@]};i++));do
	   cd ${DIFF_GITS[i]}
	   git status
	   repo upload . 
	   cd -

	done
}

##########
#main 
##########

function my_main(){

	if [ $# -gt 2 ] || [ a$1 = ahelp ] ;then
		bail "Usage: $0 releaseV1 releaseV2"
		exit
	fi

	if [ ! -f $1 ]; then
		bail "$1 is not exist, please check again!"
		exit
	elif [ ! -f $2 ]; then
		bail "$2 is not exist, please check again!"
		exit
	fi

	if [ -f $DIFF_FILE ];then
	   rm $DIFF_FILE
	fi

	if [ -f $REBASE_LOG ];then
	   rm $REBASE_LOG
	fi


	while [ a$cur_branch = a"" ]; do 
		echo Please input your working branch:
		read cur_branch
	done
	echo Current branch is $cur_branch

    echo Generating the current codebase manifest
	repo manifest -r -o $FILE_NAME
    echo Codebase manifest $FILE_NAME
	
	verify_codebase=`grep "$cur_branch" $FILE_NAME`

	if [ "$verify_codebase" = "" ]; then
		 bail "$FILE_NAME don't inlucde $cur_branch gits, Are you in your codebase or "
		 exit
	fi

	bail "begin to get diff gits ..."
	findDiffFiles $FILE_NAME $1 $2
	bail "gits needed to be rebase include in $DIFF_FILE ..."

	bail "create branch $cur_branch for all gits ...."
	repo start $cur_branch --all

	bail "begin to rebase ..."
	exec_rebase
}

my_main "$@"