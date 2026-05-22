def main():
    print("hello, world")
    print(__name__)

# import를 당했을 때  __main__이 아니게 된다.
if __name__ == "__main__":
    main()