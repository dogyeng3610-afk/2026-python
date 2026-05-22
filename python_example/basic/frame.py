import sys

frame = sys._getframe()
print("현재 프레임: ", frame)
print("코드 객체: ", frame.f_code)
print("로컬 변수: ", frame.f_locals)
# 전역 공간의 변수 
print("전역 변수: ", frame.f_globals)
print("module_frame co name: ", frame.f_code.co_name) # <module>
# 전역 = 로컬 동일 0x743688529c40
print(locals()) 
print(globals())


def main():
    a = 123
    b = [3,4,5]
    main_frame = sys._getframe()
    print("main_frame co name: ", main_frame.f_code.co_name) # main
    print("local 변수: ", main_frame.f_locals)
    print("global 변수: ", main_frame.f_globals)

if __name__ == "__main__":
    main()