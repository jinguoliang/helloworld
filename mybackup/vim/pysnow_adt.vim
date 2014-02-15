" Vim global tool plugin for android development
" Last Change:  2013 Aug 3
" Maintainer:   Nicholas Charles <pysnow530@gmail.com>
" License:      This file is placed in the public domain.

if exists("g:loaded_pysnow_adt")
    finish
endif
let g:loaded_pysnow_adt = 1

let s:err0 = '%s: command not find'
let s:err1 = 'project path not find'
let s:err2 = '%s: cannot be null'

let s:package = "com.jinux.test"

" determine the terminal
let s:term = $COLORTERM
if s:term == ''
    s:term = s:Which('xterm')
endif

" determine which command
function s:Which(filename)
    for p in split($PATH, ':')
        let pathname = join([p, a:filename], '/')
        if filereadable(pathname)
            return pathname
        endif
    endfor
    return ''
endfunction

" determine the project path
function s:GetProjectPath()
    let cwd = getcwd()
    while (cwd != '/')
        if filereadable(cwd . '/build.xml')
            return cwd
        else
            let cwd = '/' . join(split(cwd, '/')[:-2], '/')
        endif
    endwhile
    return ''
endfunction

" determine the project name
function s:GetProjectName()
    let project_path = s:GetProjectPath()
    let paths = split(project_path, '/')
    if len(paths) < 1
        return ''
    else
        return paths[-1]
    endif
endfunction

" determine if the given string is ''
function s:IsNullString(s)
    return a:s == ''? 1 : 0
endfunction

if s:IsNullString(s:GetProjectName())
    finish
endif

function s:Make()
    let ant = s:Which('ant')
    let project = s:GetProjectPath()
    if s:IsNullString(project)
        echo s:err1
    elseif s:IsNullString(ant)
        echo printf(s:err0, 'ant')
    else
        exe printf('!%s -f %s/build.xml debug', ant, project)
    endif
endfunction

function s:Install()
    let ant = s:Which('ant')
    let project = s:GetProjectPath()
    if s:IsNullString(project)
        echo s:err1
    elseif s:IsNullString(ant)
        echo printf(s:err0, 'ant')
    else
        exe printf('!%s -f %s/build.xml debug install', ant, project)
    endif
endfunction

function s:Run()
    let adb = s:Which('adb')
    let project = s:GetProjectPath()
    if s:IsNullString(project)
        echo s:err1
    elseif s:IsNullString(adb)
        echo printf(s:err0, 'adb')
    else
        exe printf('!adb shell am start -n %s/%s', s:package . '.' . tolower(s:GetProjectName()), '.' . s:GetProjectName())
    endif
endfunction

" search pattern from logcat
function s:Logcat()
    let adb = s:Which('adb')
    let grep = s:Which('grep')
    let grep_opt = ' --color=auto '

    if s:IsNullString(adb)
        echo printf(s:err0, 'adb')
    elseif s:IsNullString(grep)
        echo printf(s:err0, 'grep')
    else
        let pattern = input('/')
        exe printf('!%s logcat | %s %s "%s"', adb, grep, grep_opt, pattern)
    endif
endfunction

" logcat clear
function s:LogcatClear()
    let adb = s:Which('adb')

    if s:IsNullString(adb)
        echo printf(s:err0, 'adb')
    else
        exe printf('!%s logcat -c', adb)
    endif
endfunction

" connect the remote android shell
function s:Shell()
    let adb = s:Which('adb')
    if s:IsNullString(adb)
        echo printf(s:err0, 'adb')
    else
        exe printf('!%s shell', adb)
    endif
endfunction

" open an emulator
function s:Emulator()
    let emulator = s:Which('emulator')
    let emulator_opt = ' -avd '
    let avd = ' AVD_for_Nexus_One_by_Google '
    if s:IsNullString(emulator)
        echo printf(s:err0, 'emulator')
    else
        exe printf('!%s %s %s >/dev/null 2>/dev/null &', emulator, emulator_opt, avd)
    endif
endfunction

function s:EditManifest()
    let project_path = s:GetProjectPath()

    if s:IsNullString(project_path)
        echo s:err2
    else
        exe printf('e %s/AndroidManifest.xml', project_path)
    endif
endfunction

function s:EditLayout()
    let project_path = s:GetProjectPath()

    if s:IsNullString(project_path)
        echo s:err2
    else
        exe printf('e %s/res/layout', project_path)
    endif
endfunction

function s:EditValues()
    let project_path = s:GetProjectPath()

    if s:IsNullString(project_path)
        echo s:err2
    else
        exe printf('e %s/res/values', project_path)
    endif
endfunction

function s:EditSource()
    let project_path = s:GetProjectPath()
    let project_name = s:GetProjectName()

    if s:IsNullString(project_path)
        echo s:err2
    else
        exe printf('e %s/src/%s', project_path, join(split(s:package, '\.'), '/'))
    endif
endfunction

function s:Test()
    echo s:GetProjectName()
endfunction

" code
ab      fvbi    findViewById

" layout
ab      ll      LinearLayout
ab      rl      RelativeLayout
ab      fl      FrameLayout

" layout element
ab      bt      Button
ab      et      EditText
ab      tv      TextView

" layout attribute key
ab      ah      android:hint
ab      ai      android:id
ab      alh     android:layout_height
ab      alt     android:layout_weight
ab      alw     android:layout_width
ab      aoc     android:onClick
ab      at      android:text

" layout attribut value
ab      mp      match_parent
ab      wc      wrap_content


map <unique> ,m :call <SID>Make()<Cr>
map <unique> ,i :call <SID>Install()<Cr>
map <unique> ,r :call <SID>Run()<Cr>
map <unique> ,l :call <SID>Logcat()<Cr>
map <unique> ,c :call <SID>LogcatClear()<Cr>
map <unique> ,s :call <SID>Shell()<Cr>
map <unique> ,a :call <SID>Emulator()<Cr>
map <unique> ,em :call <SID>EditManifest()<Cr>
map <unique> ,el :call <SID>EditLayout()<Cr>
map <unique> ,ev :call <SID>EditValues()<Cr>
map <unique> ,es :call <SID>EditSource()<Cr>
map <unique> ,t :call <SID>Test()<Cr>
