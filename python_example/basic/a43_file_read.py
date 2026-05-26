import sys
from pathlib import Path

def main():
    path = Path(r"/home/dog0/2026/2026-python/python_example/data")
    with open(path / 'text.txt', 'r') as f:
        # data = f.readlines()
        # print(data)

        # for str in data:
        #     print(str)
        
        # data = f.read()
        # print(data)

        # 파일이 클때   
        while data := f.readline():
            print(data) 

    print(sys.stdin.fileno())
    print(sys.stdout.fileno())
    print(sys.stderr.fileno())
    print("error message", file=sys.stderr) # file descripter 2번에서 나가는 메세지
    with open(path / 'text.txt', 'a', encoding="utf-8") as f:
        print("이것은 프린트로 파일을 쓴 데이터이다.", file=f)

if __name__ == "__main__":
    main()