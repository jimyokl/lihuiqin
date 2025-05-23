
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
------------------------------------------may23--fengxinanli e320本地删除了1文件,增加了2个todel------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
yan@DESKTOP-MGFDE09:~/lihuiqin$ git status
On branch main
Your branch is up to date with 'origin/main'.
Changes not staged for commit:
  (use "git add/rm <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        deleted:    zab_file_IO/zab_file_ptr_offset.js
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        zab_file_IO/todel_zab_file_ptr_offset_feng_xi_nan_li.js
        zab_file_IO/zac_must_set_pos_FUNC_calculate_new_pos_feng_xi_nan_li.js
no changes added to commit (use "git add" and/or "git commit -a")

yan@DESKTOP-MGFDE09:~/lihuiqin$ git stash push -m "save before pulling origin/main"
Saved working directory and index state On main: save before pulling origin/main

yan@DESKTOP-MGFDE09:~/lihuiqin$ git pull
remote: Enumerating objects: 66, done.
remote: Counting objects: 100% (66/66), done.
remote: Compressing objects: 100% (43/43), done.
remote: Total 58 (delta 25), reused 47 (delta 15), pack-reused 0 (from 0)
Unpacking objects: 100% (58/58), 941.13 KiB | 298.00 KiB/s, done.
From https://github.com/jimyokl/lihuiqin
   0a775c2..29b1895  main       -> origin/main
Updating 0a775c2..29b1895
Fast-forward
 aaa_data_type_var_operator/xzz_ascII.c                             |   12 +
 ach_v38_character_array/{Makefile_fengxinanli => Makefile}         |    4 -
 ach_v38_character_array/aci_v39_strcpy_snprintf.c                  |    3 +-
 ach_v38_character_array/acj_v39_scanf.c                            |   64 ++++
 ach_v38_character_array/ack_fscanf.js                              | 1527 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 ach_v38_character_array/{acj_v39_strcat.c => acl_v39_strcat.c}     |    0
 ach_v38_character_array/gets_puts_v38_init_fengxinanli.c           |   32 --
 ach_v38_character_array/strcpy_scanf_printf_v39_init_fengxinanli.c |   21 --
 ach_v38_character_array/zaa_strchr_.js                             |  138 +++++++++
 ach_v38_character_array/zab_snprintf.c                             |   20 ++
 ach_v38_character_array/zab_snprintf_.js                           |   72 +++++
 ach_v38_character_array/zac_strstr.c                               |  273 ++++++++++++++++
 zab_file_IO/yaa_fpos/yaa_f_pos_get_full_length.c                   |  542 --------------------------------
 zab_file_IO/yaa_fpos/yac_file_ptr_offset_kernel_offset.js          |  145 +++++++++
 zab_file_IO/yaa_fpos/yad_get_size_from_FILE.js                     |  130 ++++++++
 zab_file_IO/yab_extract_chrome_cookie/Local State                  |    1 +
 zab_file_IO/yab_extract_chrome_cookie/Makefile                     |   38 +++
 zab_file_IO/yab_extract_chrome_cookie/bak/main_bak_1.c             |   94 ++++++
 zab_file_IO/yab_extract_chrome_cookie/bak/main_bak_2.c             |  132 ++++++++
 zab_file_IO/yab_extract_chrome_cookie/bak/main_bak_3.c             |  348 +++++++++++++++++++++
 zab_file_IO/yab_extract_chrome_cookie/chrome_cookie_main_may22.c   |  329 ++++++++++++++++++++
 zab_file_IO/yab_extract_chrome_cookie/chrome_cookies_copy.db       |  Bin 0 -> 1802240 bytes
 zab_file_IO/yab_extract_chrome_cookie/extract_chrome_cookie.md     |   40 +++
 zab_file_IO/yab_extract_chrome_cookie/main.c                       |  329 ++++++++++++++++++++
 zab_file_IO/yab_extract_chrome_cookie/z_Local_State                |    1 +
 zab_file_IO/zab_file_ptr_offset.js                                 |  927 ++++++++++++++++---------------------------------------
 zab_file_IO/zac_must_set_pos_FUNC_calculate_new_pos.js             |  292 ++++++++++++++++++
 zab_file_IO/zad_filesize_eof.js                                    |  178 +++++++++++
 zab_file_IO/zae_glibc_offset_cache.js                              |  107 +++++++
 29 files changed, 4532 insertions(+), 1267 deletions(-)
 create mode 100644 aaa_data_type_var_operator/xzz_ascII.c
 rename ach_v38_character_array/{Makefile_fengxinanli => Makefile} (90%)
 create mode 100644 ach_v38_character_array/acj_v39_scanf.c
 create mode 100644 ach_v38_character_array/ack_fscanf.js
 rename ach_v38_character_array/{acj_v39_strcat.c => acl_v39_strcat.c} (100%)
 delete mode 100644 ach_v38_character_array/gets_puts_v38_init_fengxinanli.c
 delete mode 100644 ach_v38_character_array/strcpy_scanf_printf_v39_init_fengxinanli.c
 create mode 100644 ach_v38_character_array/zaa_strchr_.js
 create mode 100644 ach_v38_character_array/zab_snprintf.c
 create mode 100644 ach_v38_character_array/zab_snprintf_.js
 create mode 100644 ach_v38_character_array/zac_strstr.c
 create mode 100644 zab_file_IO/yaa_fpos/yac_file_ptr_offset_kernel_offset.js
 create mode 100644 zab_file_IO/yaa_fpos/yad_get_size_from_FILE.js
 create mode 100755 zab_file_IO/yab_extract_chrome_cookie/Local State
 create mode 100644 zab_file_IO/yab_extract_chrome_cookie/Makefile
 create mode 100644 zab_file_IO/yab_extract_chrome_cookie/bak/main_bak_1.c
 create mode 100644 zab_file_IO/yab_extract_chrome_cookie/bak/main_bak_2.c
 create mode 100644 zab_file_IO/yab_extract_chrome_cookie/bak/main_bak_3.c
 create mode 100644 zab_file_IO/yab_extract_chrome_cookie/chrome_cookie_main_may22.c
 create mode 100644 zab_file_IO/yab_extract_chrome_cookie/chrome_cookies_copy.db
 create mode 100644 zab_file_IO/yab_extract_chrome_cookie/extract_chrome_cookie.md
 create mode 100644 zab_file_IO/yab_extract_chrome_cookie/main.c
 create mode 100644 zab_file_IO/yab_extract_chrome_cookie/z_Local_State
 create mode 100644 zab_file_IO/zac_must_set_pos_FUNC_calculate_new_pos.js
 create mode 100644 zab_file_IO/zad_filesize_eof.js
 create mode 100644 zab_file_IO/zae_glibc_offset_cache.js

yan@DESKTOP-MGFDE09:~/lihuiqin$ git stash pop
CONFLICT (modify/delete): zab_file_IO/zab_file_ptr_offset.js deleted in Stashed changes and modified in Updated upstream. Version Updated upstream of zab_file_IO/zab_file_ptr_offset.js left in tree.
On branch main
Your branch is up to date with 'origin/main'.
                                                                        ////
Unmerged paths:
  (use "git restore --staged <file>..." to unstage)
  (use "git add/rm <file>..." as appropriate to mark resolution)
        deleted by them: zab_file_IO/zab_file_ptr_offset.js

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        zab_file_IO/todel_zab_file_ptr_offset_feng_xi_nan_li.js
        zab_file_IO/zac_must_set_pos_FUNC_calculate_new_pos_feng_xi_nan_li.js
                                                                                        ////
no changes added to commit (use "git add" and/or "git commit -a")
The stash entry is kept in case you need it again.

yan@DESKTOP-MGFDE09:~/lihuiqin$ git restore --staged zab_file_IO/zab_file_ptr_offset.js
yan@DESKTOP-MGFDE09:~/lihuiqin$ git restore zab_file_IO/zab_file_ptr_offset.js

yan@DESKTOP-MGFDE09:~/lihuiqin$ git stash list
stash@{0}: On main: save before pulling origin/main

yan@DESKTOP-MGFDE09:~/lihuiqin$ git stash pop
CONFLICT (modify/delete): zab_file_IO/zab_file_ptr_offset.js deleted in Stashed changes and modified in Updated upstream. Version Updated upstream of zab_file_IO/zab_file_ptr_offset.js left in tree.
On branch main
Your branch is up to date with 'origin/main'.
                                                                        /////
Unmerged paths:
  (use "git restore --staged <file>..." to unstage)
  (use "git add/rm <file>..." as appropriate to mark resolution)
        deleted by them: zab_file_IO/zab_file_ptr_offset.js
                                                                        //////
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        zab_file_IO/todel_zab_file_ptr_offset_feng_xi_nan_li.js
        zab_file_IO/zac_must_set_pos_FUNC_calculate_new_pos_feng_xi_nan_li.js

no changes added to commit (use "git add" and/or "git commit -a")
The stash entry is kept in case you need it again.

yan@DESKTOP-MGFDE09:~/lihuiqin$ git add zab_file_IO/zab_file_ptr_offset.js
yan@DESKTOP-MGFDE09:~/lihuiqin$ git commit -m "Resolved conflict by keeping remote version of zab_file_ptr_offset.js"
On branch main
Your branch is up to date with 'origin/main'.
                                                                /////
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        zab_file_IO/todel_zab_file_ptr_offset_feng_xi_nan_li.js
        zab_file_IO/zac_must_set_pos_FUNC_calculate_new_pos_feng_xi_nan_li.js
                                                                                /////
nothing added to commit but untracked files present (use "git add" to track)

yan@DESKTOP-MGFDE09:~/lihuiqin$ rm zab_file_IO/todel_zab_file_ptr_offset_feng_xi_nan_li.js
yan@DESKTOP-MGFDE09:~/lihuiqin$ git status
On branch main
Your branch is up to date with 'origin/main'.

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        zab_file_IO/zac_must_set_pos_FUNC_calculate_new_pos_feng_xi_nan_li.js

nothing added to commit but untracked files present (use "git add" to track)
yan@DESKTOP-MGFDE09:~/lihuiqin$ rm zab_file_IO/zac_must_set_pos_FUNC_calculate_new_pos_feng_xi_nan_li.js
yan@DESKTOP-MGFDE09:~/lihuiqin$ git status
On branch main
Your branch is up to date with 'origin/main'.

nothing to commit, working tree clean

ask: 远程的 origin/main已经做了很多改变，该怎么办
a: 如果远程的 origin/main 已经做了很多改变，而你本地也有一些更改（比如文件删除、添加），那么你拉取远程更改之前要小心，避免引发冲突或丢失本地修改。

下面是几种常见的处理方式，你可以根据自己的意图选择合适的方式👇

推荐方式：使用 git stash 暂存本地更改，然后拉取
📦 1. 暂存当前本地改动（保存你的删除和新文件）：
git stash push -m "save before pulling origin/main"
🔄 2. 拉取远程代码
git pull
♻️ 3. 恢复刚才暂存的改动
git stash pop
🔧 如果冲突发生在 stash pop 时再解决就行（比起直接合并要安全些）。


第一步：暂存当前改动
在你的项目目录下运行以下命令：
git stash push -m "save before pulling origin/main"
这条命令会：

保存你所有本地的更改（包括删除、修改、未 add 的文件）

回到一个干净的工作区状态（可以安全地 git pull）


第二步：拉取远程更新
git pull
这会把远程分支的最新更改合并进来。如果没有冲突，下一步就可以恢复你的改动。



第三步：恢复你刚才的改动
git stash pop
这会把刚才 stash 的内容重新应用回来。如果有冲突，Git 会提示你解决。


如果有冲突，Git 会提示你解决冲突，你只需按提示编辑文件、git add、再 git commit 即可。
$ git stash pop
Stashed changes and modified in Updated upstream. Version Updated upstream of zab_file_IO/zab_file_ptr_offset.js left in tree.
你本地 stash 的更改中，这个文件是被删除的；
而远程更新中，这个文件被修改了；
Git 不知道你是想保留远程修改的版本，还是坚持本地删除它，所以停下来让你决策。

Unmerged paths:         deleted by them: zab_file_IO/zab_file_ptr_offset.js
Untracked files: zab_file_IO/todel_zab_file_ptr_offset_feng_xi_nan_li.js
        zab_file_IO/zac_must_set_pos_FUNC_calculate_new_pos_feng_xi_nan_li.js
你遇到了一个 典型的冲突：你本地删除了某个文件，而远程对这个文件做了修改，这在 stash pop 的时候就冲突了。


对于zab_file_IO/zab_file_ptr_offset.js， 方案 A：保留远程版本（恢复文件）
如果你希望保留远程的新版本：
git restore --staged zab_file_IO/zab_file_ptr_offset.js
git restore zab_file_IO/zab_file_ptr_offset.js 

1️⃣ git restore --staged zab_file_IO/zab_file_ptr_offset.js
意思是：❌ 取消暂存冲突状态中的文件
把这个文件从 Git 的“合并冲突区”中移出来。
⚠️ 这个命令不会还原文件内容，只是告诉 Git：“我还没决定这个文件怎么处理，不要暂存它”。
2️⃣ git restore zab_file_IO/zab_file_ptr_offset.js
意思是：✅ 把这个文件的内容还原成工作区中远程的最新版本（也就是你刚 git pull 下来的内容）
这是实际恢复文件的步骤。

恢复之后的最后一步：
git add zab_file_IO/zab_file_ptr_offset.js
git commit -m "Resolved conflict by keeping remote version of zab_file_ptr_offset.js"
这样就算是彻底解决冲突并完成合并了。

现在还有两个未被 Git 跟踪（untracked）的新文件： zab_file_IO/todel_zab_file_ptr_offset_feng_xi_nan_li.js
zab_file_IO/zac_must_set_pos_FUNC_calculate_new_pos_feng_xi_nan_li.js

yan打算删除这两个文件，那么需要运行
rm zab_file_IO/todel_zab_file_ptr_offset_feng_xi_nan_li.js
rm zab_file_IO/zac_must_set_pos_FUNC_calculate_new_pos_feng_xi_nan_li.js

运行2个rm后，git status ：nothing to commit, working tree clean


git restore --staged zab_file_IO/zab_file_ptr_offset.js
是取消暂存区的修改（把这个文件从暂存区撤回），相当于告诉 Git 不再准备把你之前本地修改的版本提交。
git restore zab_file_IO/zab_file_ptr_offset.js
是还原工作区的文件内容，把文件恢复成当前分支 HEAD（也就是你本地最新同步的远程版本）的状态。



Unmerged paths:
  (use "git restore --staged <file>..." to unstage)
  (use "git add/rm <file>..." as appropriate to mark resolution)
        deleted by them: zab_file_IO/zab_file_ptr_offset.js
反映的是 Git 在合并（stash pop 其实是合并 stash 里的改动和当前代码）时，对同一个文件发生了“冲突”，具体情况是：
“deleted by them” 表示在你 stash 的内容里，这个文件是被删除的（即你本地改动里删除了它），
但远程最新代码（也就是当前分支上的代码）中，这个文件被修改了（没有被删除，内容有变化），
这两者产生了冲突：
远程分支是“修改了文件”，
你 stash 里是“删除了文件”，
Git 不知道应该保留“修改后的文件”还是“删除文件”，所以标记为冲突。


这也正是为什么 Git 提示：
你可以用 git restore --staged <file> 取消暂存区的状态，或者
用 git add 标记解决（比如选择保留哪个版本，修改后再 add），或者
用 git rm 删除文件并标记解决冲突。


git add zab_file_IO/zab_file_ptr_offset.js 告诉 Git：“我已经解决了这个文件的冲突，现在把这个文件标记为冲突已解决，准备提交。”
这里的文件内容是你选择保留的版本（根据你的描述，是远程版本，也就是 stash 弹出时留下的远程版本）。
git commit -m "Resolved conflict by keeping remote version of zab_file_ptr_offset.js" 提交了这次冲突解决的结果，
提交说明是“通过保留远程版本解决了 zab_file_ptr_offset.js 的冲突”。

总结:
你在 stash 弹出（git stash pop）时遇到冲突； 手动选择保留了远程版本的文件；
用 git add 告诉 Git 这个冲突解决了；用 git commit 记录这次冲突解决的提交。


查看你的 stash（可选）
如果你想确认刚才暂存的内容，还可以先运行：
git stash list ，然后drop掉 stash@{0}
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------