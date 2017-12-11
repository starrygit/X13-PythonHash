from distutils.core import setup, Extension

sm3_hash_module = Extension('sm3_hash',
                               sources = ['x13module.c',
                                          'x13.c',
                                          'sha3/blake.c',
										  'sha3/sm3.c',],

                               include_dirs=['.', './sha3'])

setup (name = 'sm3_hash',
       version = '1.0',
       description = 'Bindings for proof of work used by sm3',
       ext_modules = [sm3_hash_module])
