
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
yan@DESKTOP-MGFDE09:~/lihuiqin$ git pull origin main
error: cannot pull with rebase: You have unstaged changes.
error: please commit or stash them.
yan@DESKTOP-MGFDE09:~/lihuiqin$ git add .
yan@DESKTOP-MGFDE09:~/lihuiqin$ git commit -m "e320 at feng xi nan li"
[main 70eddf4] e320 at feng xi nan li
 15 files changed, 180 insertions(+), 54 deletions(-)
 create mode 100755 a.out
 create mode 100755 aaj_v15_16_17_18_IO/a.out
 rename aaj_v15_16_17_18_IO/{aaj_v17_10min_newline_character_flush.c => aaj_v17_10min_1_newline_character_flush.c} (65%)
 create mode 100644 aaj_v15_16_17_18_IO/aaj_v17_10min_2_newline_character_no_flush_with_sleep.c
 rename aaj_v15_16_17_18_IO/{aal_v19_3_fgets_with_some_potential_drawbacks.c => aal_v19_3_1_fgets_with_some_potential_drawbacks.c} (100%)
 create mode 100644 aaj_v15_16_17_18_IO/aal_v19_3_2_fgets_fputs_puts_cppBook.c
 create mode 100644 aaj_v15_16_17_18_IO/aao_2_fscanf.c
 create mode 100755 aap_2_formatted_IO_test/a.out
 create mode 100644 aap_2_formatted_IO_test/aap_2_quart_water_quiz.c
yan@DESKTOP-MGFDE09:~/lihuiqin$ git pull origin main
remote: Enumerating objects: 60, done.
remote: Counting objects: 100% (60/60), done.
remote: Compressing objects: 100% (24/24), done.
remote: Total 46 (delta 31), reused 35 (delta 20), pack-reused 0 (from 0)
Unpacking objects: 100% (46/46), 16.86 KiB | 130.00 KiB/s, done.
From https://github.com/jimyokl/lihuiqin
 * branch            main       -> FETCH_HEAD
   fe65553..cf1a9b0  main       -> origin/main
Auto-merging aaj_v15_16_17_18_IO/aak_v18_scanf_1.c
CONFLICT (content): Merge conflict in aaj_v15_16_17_18_IO/aak_v18_scanf_1.c
Auto-merging aaj_v15_16_17_18_IO/aam_fprintf_fwrite_text_data_file_binary_data_file.c
CONFLICT (content): Merge conflict in aaj_v15_16_17_18_IO/aam_fprintf_fwrite_text_data_file_binary_data_file.c
Auto-merging aaj_v15_16_17_18_IO/t
CONFLICT (content): Merge conflict in aaj_v15_16_17_18_IO/t
Auto-merging note/aag_v9_v10_variable.md
error: could not apply 70eddf4... e320 at feng xi nan li
hint: Resolve all conflicts manually, mark them as resolved with
hint: "git add/rm <conflicted_files>", then run "git rebase --continue".
hint: You can instead skip this commit: run "git rebase --skip".
hint: To abort and get back to the state before "git rebase", run "git rebase --abort".
Could not apply 70eddf4... e320 at feng xi nan li
yan@DESKTOP-MGFDE09:~/lihuiqin$ cd
yan@DESKTOP-MGFDE09:~$ vim .git
.git/       .gitconfig
yan@DESKTOP-MGFDE09:~$ vim .git
.git/       .gitconfig
yan@DESKTOP-MGFDE09:~$ vim .gitconfig
yan@DESKTOP-MGFDE09:~$
yan@DESKTOP-MGFDE09:~$ cd lihuiqin/
yan@DESKTOP-MGFDE09:~/lihuiqin$ ls
README.md    aab_dont_forget_head_file.c          aae_v5_data_type.c        aag_v9_10_2_global_var.c                                      aaj_v15_16_17_18_IO      deepseek
a.out        aac_warning_lead_to_segment_fault.c  aaf_v8_define.c           aah_v11_multi_file_programming_staticGlobalVar_staticFUNC_AI  aap_2_formatted_IO_test  media
aaa_hello.c  aad_hello.c                          aag_v9_10_1_global_var.c  aai_v12_13_14_operator_expression.c                           aar_v20_IO_thematic      note
yan@DESKTOP-MGFDE09:~/lihuiqin$ git pull origin main
error: Pulling is not possible because you have unmerged files.
hint: Fix them up in the work tree, and then use 'git add/rm <file>'
hint: as appropriate to mark resolution and make a commit.
fatal: Exiting because of an unresolved conflict.
yan@DESKTOP-MGFDE09:~/lihuiqin$ git status
interactive rebase in progress; onto cf1a9b0
Last command done (1 command done):
   pick 70eddf4 e320 at feng xi nan li
No commands remaining.
You are currently rebasing branch 'main' on 'cf1a9b0'.
  (fix conflicts and then run "git rebase --continue")
  (use "git rebase --skip" to skip this patch)
  (use "git rebase --abort" to check out the original branch)

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        new file:   a.out
        modified:   aai_v12_13_14_operator_expression.c
        new file:   aaj_v15_16_17_18_IO/a.out
        modified:   aaj_v15_16_17_18_IO/aaj_v15_16_17_printf.c
        renamed:    aaj_v15_16_17_18_IO/aaj_v17_10min_newline_character_flush.c -> aaj_v15_16_17_18_IO/aaj_v17_10min_1_newline_character_flush.c
        new file:   aaj_v15_16_17_18_IO/aaj_v17_10min_2_newline_character_no_flush_with_sleep.c
        renamed:    aaj_v15_16_17_18_IO/aal_v19_3_fgets_with_some_potential_drawbacks.c -> aaj_v15_16_17_18_IO/aal_v19_3_1_fgets_with_some_potential_drawbacks.c
        new file:   aaj_v15_16_17_18_IO/aal_v19_3_2_fgets_fputs_puts_cppBook.c
        new file:   aaj_v15_16_17_18_IO/aao_2_fscanf.c
        new file:   aap_2_formatted_IO_test/a.out
        new file:   aap_2_formatted_IO_test/aap_2_quart_water_quiz.c
        modified:   note/aag_v9_v10_variable.md

Unmerged paths:
  (use "git restore --staged <file>..." to unstage)
  (use "git add <file>..." to mark resolution)
        both modified:   aaj_v15_16_17_18_IO/aak_v18_scanf_1.c
        both modified:   aaj_v15_16_17_18_IO/aam_fprintf_fwrite_text_data_file_binary_data_file.c
        both modified:   aaj_v15_16_17_18_IO/t
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
然后我备份了冲突的文件，把conflict（both modified）的3个文件mv到了~目录
然后再用git pull origin main, 报错

yan@DESKTOP-MGFDE09:~/lihuiqin$ git pull origin main
error: Pulling is not possible because you have unmerged files.
hint: Fix them up in the work tree, and then use 'git add/rm <file>'
hint: as appropriate to mark resolution and make a commit.
fatal: Exiting because of an unresolved conflict.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
然后我继续错误操作，git add， git commit， git push， 报错发现了还未完成的git pull
yan@DESKTOP-MGFDE09:~/lihuiqin$ git add .
yan@DESKTOP-MGFDE09:~/lihuiqin$ git commit -m "e320 commit again after conflict"
[detached HEAD be17939] e320 commit again after conflict
 15 files changed, 150 insertions(+), 175 deletions(-)
 create mode 100755 a.out
 create mode 100755 aaj_v15_16_17_18_IO/a.out
 rename aaj_v15_16_17_18_IO/{aaj_v17_10min_newline_character_flush.c => aaj_v17_10min_1_newline_character_flush.c} (65%)
 create mode 100644 aaj_v15_16_17_18_IO/aaj_v17_10min_2_newline_character_no_flush_with_sleep.c
 delete mode 100644 aaj_v15_16_17_18_IO/aak_v18_scanf_1.c
 rename aaj_v15_16_17_18_IO/{aal_v19_3_fgets_with_some_potential_drawbacks.c => aal_v19_3_1_fgets_with_some_potential_drawbacks.c} (100%)
 create mode 100644 aaj_v15_16_17_18_IO/aal_v19_3_2_fgets_fputs_puts_cppBook.c
 delete mode 100644 aaj_v15_16_17_18_IO/aam_fprintf_fwrite_text_data_file_binary_data_file.c
 create mode 100644 aaj_v15_16_17_18_IO/aao_2_fscanf.c
 delete mode 100644 aaj_v15_16_17_18_IO/t
 create mode 100755 aap_2_formatted_IO_test/a.out
 create mode 100644 aap_2_formatted_IO_test/aap_2_quart_water_quiz.c

***********报错 error： 发现之前已经有rebase进程了

From https://github.com/jimyokl/lihuiqin
 * branch            main       -> FETCH_HEAD
fatal: It seems that there is already a rebase-merge directory, and
I wonder if you are in the middle of another rebase.  If that is the
case, please try
        git rebase (--continue | --abort | --skip)
If that is not the case, please
        rm -fr ".git/rebase-merge"
and run me again.  I am stopping in case you still have something
valuable there.

******** 取消这次的rebase

yan@DESKTOP-MGFDE09:~/lihuiqin$ git rebase --abort

********继续之前那次的rebase，报错，因为需要用 git rm 命令把冲突的文件删除

yan@DESKTOP-MGFDE09:~/lihuiqin$ git rebase --continue
fatal: No rebase in progress?


yan@DESKTOP-MGFDE09:~/lihuiqin$ git pull origin main
From https://github.com/jimyokl/lihuiqin
 * branch            main       -> FETCH_HEAD
Auto-merging aaj_v15_16_17_18_IO/aak_v18_scanf_1.c
CONFLICT (content): Merge conflict in aaj_v15_16_17_18_IO/aak_v18_scanf_1.c
Auto-merging aaj_v15_16_17_18_IO/aam_fprintf_fwrite_text_data_file_binary_data_file.c
CONFLICT (content): Merge conflict in aaj_v15_16_17_18_IO/aam_fprintf_fwrite_text_data_file_binary_data_file.c
Auto-merging aaj_v15_16_17_18_IO/t
CONFLICT (content): Merge conflict in aaj_v15_16_17_18_IO/t
Auto-merging note/aag_v9_v10_variable.md
error: could not apply 70eddf4... e320 at feng xi nan li
hint: Resolve all conflicts manually, mark them as resolved with
hint: "git add/rm <conflicted_files>", then run "git rebase --continue".
hint: You can instead skip this commit: run "git rebase --skip".
hint: To abort and get back to the state before "git rebase", run "git rebase --abort".
Could not apply 70eddf4... e320 at feng xi nan li

******上面几行提示用 git rm命令 

yan@DESKTOP-MGFDE09:~/lihuiqin$ git rm aaj_v15_16_17_18_IO/aak_v18_scanf_1.c
rm 'aaj_v15_16_17_18_IO/aak_v18_scanf_1.c'

yan@DESKTOP-MGFDE09:~/lihuiqin$ git aaj_v15_16_17_18_IO/aam_fprintf_fwrite_text_data_file_binary_data_file.c
git: 'aaj_v15_16_17_18_IO/aam_fprintf_fwrite_text_data_file_binary_data_file.c' is not a git command. See 'git --help'.

yan@DESKTOP-MGFDE09:~/lihuiqin$ git aaj_v15_16_17_18_IO/t
git: 'aaj_v15_16_17_18_IO/t' is not a git command. See 'git --help'.

yan@DESKTOP-MGFDE09:~/lihuiqin$ git rm  aaj_v15_16_17_18_IO/t
rm 'aaj_v15_16_17_18_IO/t'
yan@DESKTOP-MGFDE09:~/lihuiqin$ git rm aaj_v15_16_17_18_IO/aam_fprintf_fwrite_text_data_file_binary_data_file.c
rm 'aaj_v15_16_17_18_IO/aam_fprintf_fwrite_text_data_file_binary_data_file.c'

####*** *****************  可以继续前面那次的rebase了

yan@DESKTOP-MGFDE09:~/lihuiqin$ git rebase --continue
[detached HEAD c8403e3] e320 at feng xi nan li
 15 files changed, 150 insertions(+), 175 deletions(-)
 create mode 100755 a.out
 create mode 100755 aaj_v15_16_17_18_IO/a.out
 rename aaj_v15_16_17_18_IO/{aaj_v17_10min_newline_character_flush.c => aaj_v17_10min_1_newline_character_flush.c} (65%)
 create mode 100644 aaj_v15_16_17_18_IO/aaj_v17_10min_2_newline_character_no_flush_with_sleep.c
 delete mode 100644 aaj_v15_16_17_18_IO/aak_v18_scanf_1.c
 rename aaj_v15_16_17_18_IO/{aal_v19_3_fgets_with_some_potential_drawbacks.c => aal_v19_3_1_fgets_with_some_potential_drawbacks.c} (100%)
 create mode 100644 aaj_v15_16_17_18_IO/aal_v19_3_2_fgets_fputs_puts_cppBook.c
 delete mode 100644 aaj_v15_16_17_18_IO/aam_fprintf_fwrite_text_data_file_binary_data_file.c
 create mode 100644 aaj_v15_16_17_18_IO/aao_2_fscanf.c
 delete mode 100644 aaj_v15_16_17_18_IO/t
 create mode 100755 aap_2_formatted_IO_test/a.out
 create mode 100644 aap_2_formatted_IO_test/aap_2_quart_water_quiz.c
Successfully rebased and updated refs/heads/main.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

pull（rebase）成功后， 把之前~目录里面的文件改名，复制到lihuiqin文件夹，再push到远端

yan@DESKTOP-MGFDE09:~/lihuiqin$ git commit -m "mar27 0119 push e320 local to x220"
[main c437636] mar27 0119 push e320 local to x220
 3 files changed, 167 insertions(+)
 create mode 100644 aaj_v15_16_17_18_IO/aam_fprintf_fwrite_text_data_file_binary_data_file.c
 create mode 100644 aaj_v15_16_17_18_IO/t_mod
 create mode 100644 aak_v18_scanf_1_mod.c
 
 yan@DESKTOP-MGFDE09:~/lihuiqin$ git push -u origin main
Enumerating objects: 29, done.
Counting objects: 100% (29/29), done.
Delta compression using up to 2 threads
Compressing objects: 100% (22/22), done.
Writing objects: 100% (22/22), 13.96 KiB | 793.00 KiB/s, done.
Total 22 (delta 11), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (11/11), completed with 7 local objects.
To https://github.com/jimyokl/lihuiqin.git
   cf1a9b0..c437636  main -> main
Branch 'main' set up to track remote branch 'main' from 'origin'.
 

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------