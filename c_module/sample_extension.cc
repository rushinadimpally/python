#include <Python.h>
#include <sample_extension.h>

namespace{
  int internalSumFunc(int a, int b, int c)
  {
    return a + b + c;
  }
}

// function that needs to be exposed
static PyObject* addThree(PyObject* self,
			  PyObject* args)
{
  int a, b, c, result;
  if(!PyArg_ParseTuple(args, "iii", &a, &b, &c))
    {
      return NULL;
    }

  // note: The meat of the operation should be outside of the wrapper
  // should just concern itself with wrapping/unwrapping args and results
  result = internalSumFunc(a,b,c);

  return Py_BuildValue("i", result);  
}

// each module must have a module method table

static PyMethodDef SampleExtensionMethods[] = {
					       {"addThree", addThree, METH_VARARGS, "Adds three numbers together"},
					       {NULL, NULL, 0, NULL}
};

// module level structure
static struct PyModuleDef sampleExtensionModule = {
						   PyModuleDef_HEAD_INIT,
						   "sample_extension",
						   "sample extension module",
						   -1,
						   SampleExtensionMethods
};


PyMODINIT_FUNC PyInit_sample_extension(void) {
  return PyModule_Create(&sampleExtensionModule);
}

// Note: the function name here is very important
// if different from what the moduke name expects,
// it will result in an error that looks like this:
// --------------------------------------------------
/*ImportError      Traceback (most recent call last)
<ipython-input-60-297bc4b27d54> in <module>()
      2 import sys
      3 sys.path.append("/home/rushi/dev/git/python/c_module")
----> 4 import sample_extension

ImportError: dynamic module does not define module export function (PyInit_sample_extension)
*/
