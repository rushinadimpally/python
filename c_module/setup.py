from distutils.core import setup, Extension

# creates a module by name
setup(name='sample_extension',
      ext_modules =[
          Extension('sample_extension',
                    # compiles all of the following files
                    ['sample_extension.cc'],
                    # translates to -I
                    include_dirs=['/usr/include/python3.7/', '/home/rushi/dev/git/python/c_module/'],
                    # translates to -D
                    define_macros=[],
                    undef_macros=[],
                    # translates to -L
                    library_dirs=['/usr/local/lib', '/home/rushi/dev/git/python/c_module/'],
                    # translates to -l
                    libraries=['extension']
                    )
      ]
      )
