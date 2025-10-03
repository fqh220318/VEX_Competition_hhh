# VEX_Competition_hhh
---
## Welcome to our VEX team's repo!

接下来我要用中文写hhh

### 如何实现远程合作？
 - 让管理员将你加入collaboration名单
 - 或者fork一个自己的仓库
 - 在提交push之前先pull同步一下开发进度
 > 详细做法：  
 > dev分支随便你玩   
 > 在需要push上github时   
 > 先在main分支底下pull远程main分支   
 > 然后在dev分支rebase本地main  
 > 解决rebase冲突  
 > 回到main分支merge dev  
 > push上传
 ```
 //具体操作
 git switch main
 git pull origin main
 git switch dev
 git rebase main

 //解决冲突

 //merge合并push上传
 git switch main
 git merge dev
 git push origin main 
 ``` 

 - 解决完冲突之后push即可
 - 注意写commit message写得看得懂一点嘿嘿

### 分支说明

 - main分支：稳定的代码
 - dev分支：开发中的代码（不一定能用）

