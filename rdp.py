zzzinput_string = "(10+2)*3+4"
pos = 0

def assign():
    global zzzinput_string
    global pos
    global result
    zzzinput_string = input("Enter sum: ")
    pos = 0
    result = 0

def expression():
    global zzzinput_string
    global pos

    result = term()

    while pos < len(zzzinput_string):
        left = result
        if zzzinput_string[pos] == "+":
            pos += 1
            result = term()
            result = left + result
        elif zzzinput_string[pos] == "-":
            pos -= 1
            result = term()
            result = left - term
        else:
            break

def term():
    global zzzinput_string
    global pos
    result = factor()
    while pos < len(zzzinput_string):
        left = result
        trivia()
        if zzzinput_string[pos] == "*":
            pos += 1
            result = factor()
            result = left * result
        elif zzzinput_string[pos] == "/":
            pos += 1
            result = factor()
            if result != "0":
                result = left/result
            else:
                error = "Error: Divide by 0"
        else:
            break

def factor():
    global zzzinput_string
    global pos
    result = trivia()
    left = result
    if zzzinput_string[pos] == "(":
        pos += 1
        expression()
        if zzzinput_string[pos] == ")":
            pos += 1
        else:
            error = "No closing parenthesis"
    
    elif zzzinput_string[pos] == "+":
        pos += 1
        result = factor()
        result = left + result
    elif zzzinput_string[pos] == "-":
        pos += 1
        result = factor()
        result = left - result



    elif pos < len(zzzinput_string) and zzzinput_string[pos] >= "0" and zzzinput_string[pos] <= "9":
        result = int(zzzinput_string[pos])
        pos += 1
        while zzzinput_string[pos] >= "0" and zzzinput_string[pos] <= "9":
            result = (result * 10) + (int(zzzinput_string[pos]))
            pos += 1




def trivia():
    global zzzinput_string
    global pos
    while zzzinput_string[pos] == " ":
        pos += 1

print(expression())