input_string = "(10+2)*3+4"
pos = 0

def assign():
    global input_string
    global pos
    global result
    input_string = input("Enter sum: ")
    pos = 0
    result = 0

def expression():
    global input_string
    global pos

    result = term()

    while pos < len(input_string):
        left = result
        if input_string[pos] == "+":
            pos += 1
            result = term()
            result = left + result
        elif input_string[pos] == "-":
            pos -= 1
            result = term()
            result = left - term
        else:
            break

def term():
    global input_string
    global pos
    result = factor()
    while pos < len(input_string):
        left = result
        result = trivia()
        if input_string[pos] == "*":
            pos += 1
            result = factor()
            result = left * result
        elif input_string[pos] == "/":
            pos += 1
            result = factor()
            if result != "0":
                result = left/result
            else:
                error = "Error: Divide by 0"
        else:
            break

def factor():
    global input_string
    global pos
    result = trivia()
    left = result
    if input_string[pos] == "(":
        pos += 1
        result = expression()
        if input_string[pos] == ")":
            pos += 1
        else:
            error = "No closing parenthesis"
    
    elif input_string[pos] == "+":
        pos += 1
        result = factor()
        result = left + result
    elif input_string[pos] == "-":
        pos += 1
        result = factor()
        result = left - result



    elif pos < len(input_string) and input_string[pos] >= "0" and input_string[pos] <= "9":
        result = int(input_string[pos])
        pos += 1
        while input_string[pos] >= "0" and input_string[pos] <= "9":
            result = (result * 10) + (int(input_string[pos]))
            pos += 1




def trivia():
    global input_string
    global pos
    while input_string[pos] == " ":
        pos += 1

print(expression())
