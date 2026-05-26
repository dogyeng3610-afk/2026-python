# int main(int argc, char *argv[]) -> 
# argparser 라이브러리(패키지)
import sys


def main():
    # print(sys.argv[0])
    #  /usr/bin/python3 /home/dog0/2026/2026-python/python_example/basic/a103_main_argument.py abc
    # print(sys.argv[1])


    # /usr/bin/python3 /home/dog0/2026/2026-python/python_example/basic/a103_main_argument.py
    # 사용법: 로드할 파일을 명시하시오!
    # /usr/bin/python3 /home/dog0/2026/2026-python/python_example/basic/a103_main_argument.py ㅎㅎㅎㅎㅎㅎ
    # 정상 작동
    if len(sys.argv) < 2:
        print("사용법: 로드할 파일을 명시하시오!")
        sys.exit()
    # with open(sys.argv[1]) as f:
    #     pass
    print("정상 작동")

if __name__ == "__main__":
    main()