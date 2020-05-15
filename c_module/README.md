# Steps to create the so:
# write sample.h
# write sample.cc which includes sample.h

# Create the shared library module
# rushi@rushi-study:~/dev/git/python/c_module$ g++ -I./ -shared -o libsample.so sample.cc
# creates libsample.so

# create a main which uses the functions from sample.h
# use the shared library module
rushi@rushi-study:~/dev/git/python/c_module$ g++ -I./ -L./ main.cc -l sample

# without ld_library_path, we get error:
rushi@rushi-study:~/dev/git/python/c_module$ ./a.out
./a.out: error while loading shared libraries: libsample.so: cannot open shared object file: No such file or directory


# with library path, it works
rushi@rushi-study:~/dev/git/python/c_module$ LD_LIBRARY_PATH=./ ./a.out
2


# for python extensions, it's necessary to also add the python include path:
rushi@rushi-study:~/dev/git/python/c_module$ g++ -I./ -I /usr/include/python3.7/ -shared -o lib
extension.so sample_extension.cc

# create the library above
# and then also create a setup.py file
# as shown in this directroy and run:
rushi@rushi-study:~/dev/git/python/c_module$ python3 setup.py build_ext --inplace