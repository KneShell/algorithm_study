def get_middle(s):
    string_length = len(s)

    if string_length % 2 == 0:
        even_index = int(string_length/2)
        return s[even_index - 1] + s[even_index]
    else:
        if string_length == 1:
            return s
        else:
            odd_index = int(string_length/2)
            return s[odd_index]

print( get_middle("test") )
print( get_middle("testing") )
print( get_middle("middle") )
print( get_middle("A") )
print( get_middle("of") )
