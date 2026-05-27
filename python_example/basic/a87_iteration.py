from collections.abc import Iterable

class SimpleIter:
    def __init__(self, start, end):
        self.current = start
        self.end = end

    def __iter__(self):
        return self
    
    def __next__(self):
        if self.current >= self.end:
            raise StopIteration
        value = self.current
        self.current += 1
        return value
    
# iterable한지 확인
# next 설계시 끊길 수 있도록 설계
def main():
    print(isinstance(SimpleIter(1,5), Iterable))

    for i in SimpleIter(1, 5):
        print(i)

if __name__ == "__main__":
    main()