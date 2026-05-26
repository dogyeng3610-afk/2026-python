class Test:
    def __init__(self, name):
        self.name = name
        print(f"{self.name}이 생성되었습니다.")

    def __del__(self):
        print(f"{self.name} - 파괴 되었습니다.")

    # def __new__(self): 명확하지 않는 이상 사용x

def main():
    a = Test("a")
    b = Test("b")
    c = Test("c")
    print(a, b, c)
    del c # c가 먼저 파괴


if __name__ == "__main__":
    main()