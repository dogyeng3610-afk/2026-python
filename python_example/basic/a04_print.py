class A:
    def __repr__(self):
        return "this is class A!!!!-by KDG"
    # c++ 멤버 함수, method, 클래스 내 클래스 행위 지정
    # 문자열을 내보내고 싶을 때

def main():
    print(12345)
    print(1_234_567)
    # 더블 쿼티와 싱글 쿼티 차이 없음
    print("kim dogyeong")
    print('python "class"')
    # 소수
    print(3.142592)

    # \t, \n 등 escape 문자 사용 가능
    print("this is", "python", "class!!!")
    print(10, 20, 30, "hi", "fifty")
    # 엔터
    print()

    print("this is", "python", "class!!!", sep="_", end="")
    print("this is", "python", "class!!!", sep="-")
    # 클래스 정의만 했을때 pass
    # 객체 정보
    print(A())
    # class
    print(type(A()))


if __name__ == "__main__":
    main()

    # 함수 힌트 잘 읽고, 잘 작성-함수 정의 부분에 작성
    # 클래스 내에서 설정