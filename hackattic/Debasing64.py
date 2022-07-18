import base64

# decoding Base64-encoded string
def solve(n):
    string = n
    bytes = string.encode("ascii")
    string_bytes = base64.b64decode(bytes)
    res = string_bytes.decode("ascii")
    print(res)
    pass

# reading inputs  
for i in range(0,16):
    n = input()
    solve(n)