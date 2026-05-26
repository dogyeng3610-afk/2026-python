import test_package
from test_package import *
from test_package import package_func
# from test_package.module_a import module_var_a
# from test_package.module_b import module_var_b
# package 불러올 때 __init__.py 한 번만 실행(여러 번 불러도)


def main():
    print(module_var_a)
    print(module_var_b)
    module_a_func()
    print(test_package.module_var_a)
    test_package.module_b_func()
    print(test_package.Module_a())

    package_func()

# import를 당했을 때  __main__이 아니게 된다.
if __name__ == "__main__":
    main()