Import("env")
from subprocess import call
import os

print "--- pre_extra_script.py started ---"

def runCommonChecks(source, target, env):
    print("Started cppcheck...\n")
    call(["cppcheck", os.getcwd()+"/src", "--enable=all"])
    print("Finished cppcheck...\n")

# def runNativeChecks(source, target, env):
#     print("Started valgrind...\n")
#     call(["valgrind", "--leak-check=full", ".pioenvs/native/program"])
#     print("Finished valgrind...\n")

#     print("Started gcov...\n")
#     for file in os.listdir(os.getcwd()+"/src"):
#         if file.endswith(".cpp") or file.endswith(".c"):
#             call(["gcov", "--object-directory", ".pioenvs/native/src", os.getcwd()+"/src/"+file])
#     print("Finished gcov...\n")

print "Current build targets", map(str, BUILD_TARGETS)

env.AddPreAction("buildprog", runCommonChecks)
# env.AddPostAction(".pioenvs/native/program", runNativeChecks)



print "--- pre_extra_script.py ended ---"