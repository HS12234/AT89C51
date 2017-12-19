操作指南：

pwd    			显示当前目录
git init  		初始化

将文件放入仓库：
第一步，使用命令git add <file>，注意，可反复多次使用，添加多个文件；
第二步，使用命令git commit，完成。

git status   		掌握工作区状态
git diff		显示更改内容

git log			查看提交历史，以便确定要回退到哪个版本
git reflog		查看命令历史，以便确定要回到未来的哪个版本

git reset --hard HEAD^		回退到前N个版本,N为^的数量
git reset --hard 版本号		回退到某个版本


要关联一个远程库，使用命令git remote add origin git@server-name:path/repo-name.git；

取消本地目录下关联的远程库：
git remote remove origin

关联后，使用命令git push -u origin master第一次推送master分支的所有内容；

此后，每次本地提交后，只要有必要，就可以使用命令git push origin master推送最新修改；

git checkout -- file可以丢弃工作区的修改
git reset HEAD file可以把暂存区的修改撤销掉（unstage），重新放回工作区

rm file  删除文件

创建dev分支，然后切换到dev分支：
$ git checkout -b dev

$ git branch dev  创建分支dev
$ git checkout dev  切换到dev

git branch      命令会列出所有分支，当前分支前面会标一个*号。

$ git merge dev    合并分支dev到当前分支

$git merge -d dev       删除分支dev
git branch -D dev       强行删除分支dev


git log --graph       可以看到分支合并图

git stash   保存现在分支的工作情况储存

git stash list		查看储存清单

一是用git stash apply恢复，但是恢复后，stash内容并不删除，你需要用git stash drop来删除；

另一种方式是用git stash pop，恢复的同时把stash内容也删了：

git merge --no-ff -m "merge with no-ff" dev  强制禁用Fast forward模式，Git就会在merge时生成一个新的commit，这样，从分支历史上就可以看出分支信息