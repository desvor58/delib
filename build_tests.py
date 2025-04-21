import os
import subprocess

tests_dir = "test/"

for test_sourse_name in os.listdir(tests_dir):
    os.system(f"clang++ -Wall {tests_dir}/{test_sourse_name} \
        -o {tests_dir}bin/{test_sourse_name[:-3] + "exe"}")

