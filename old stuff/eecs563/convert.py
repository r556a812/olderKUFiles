def convert(myString):
    done = ''
    for c in myString:
        if c.islower():
            c = c.replace(c, c.upper())
            done = done + c
        elif c.isupper():
            done = done + c
        else:
            done = done + c

    return (done)

def main():
    a = "Happy1@@@"
    a = convert(a)
    print (a)

    b = "check4UPPer see IT w0rKs"
    b = convert(b)
    print (b)

    d = "5^^^%$#@!lower and UPPER"
    d = convert(d)
    print (d)

main()
