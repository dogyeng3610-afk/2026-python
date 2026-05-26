# import a35_variable_length_keyward_argument
# import test_package
# import test_package.module_a
# import test_package.module_b
from a35_variable_length_keyward_argument import print_n_times as pnt
from test_package.module_a import module_var_a
from python_example.basic.module_b import module_var_b
# from 파일명 import 함수 as 별칭
# 유명한 라이브러리 이름을 파일로 만들면 x 



def main():
    print("hello, world")
    print(__name__)
    # a35_variable_length_keyward_argument.print_n_times(1, 2, 3)
    # print_n_time(4, 5, 6, a="aaa")
    pnt(4, 5, 6, b="bbb")
    # print(test_package.module_a.module_var_a)
    # print(test_package.module_b.module_var_b)
    print(module_var_a)
    print(module_var_b)

# import를 당했을 때  __main__이 아니게 된다.
if __name__ == "__main__":
    main()