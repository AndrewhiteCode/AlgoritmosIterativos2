#!/bin/bash
# Replaces Opt(10) with Opt(16) in headers and code.
sed -i 's/Opt(10)/Opt(16)/g' src/generate_exec_times.c
sed -i 's/merge_sort_optimized(mergeOpt10P, k, 10, compare_id)/merge_sort_optimized(mergeOpt10P, k, 16, compare_id)/g' src/generate_exec_times.c
sed -i 's/FLAG_MERGE_OPT10/FLAG_MERGE_OPT16/g' incs/generate_exec_times.h
sed -i 's/FLAG_MERGE_OPT10/FLAG_MERGE_OPT16/g' src/smoke.c
