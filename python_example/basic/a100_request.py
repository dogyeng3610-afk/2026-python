# pip freeze >> requirments.txt
# pip install -r requirements.txt => .venv -> uv


import requests

url = "https://naver.com"
response = requests.get(url)

print("stats", response.status_code)
print("text", response.text)