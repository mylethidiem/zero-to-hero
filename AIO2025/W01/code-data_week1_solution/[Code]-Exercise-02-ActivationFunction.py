import math
def is_number(n):
    try:
        float(n)   # Type-casting the string to `float`.
                   # If string is not a valid `float`,
                   # it'll raise `ValueError` exception
    except ValueError:
        return False
    return True
assert is_number(3) == 1.0
assert is_number('-2a') == 0.0

def calc_relu(x):
    """
    Tính hàm ReLU:
    ReLU(x) = max(0, x)
    """
    if x<=0:
        result = 0.0
    else:
        result = x
    return float(result)

def calc_sig(x):
    """
    Tính hàm sigmoid: σ(x) = 1 / (1 + e^(-x))
    """
    return 1./(1+math.e**(-x))

def calc_elu(x):
    """
    Tính hàm ELU (Exponential Linear Unit):
    ELU(x) = x                 nếu x >= 0
           = alpha * (e^x - 1) nếu x < 0
    """
    alpha = 0.01
    result = None
    if x < 0:
        result = alpha*(math.e**x - 1)
    else:
        result = x
    return result
assert round(calc_elu(1))==1

def calc_activation_func(x, act_name):
    """
    Tính hàm kích hoạt cho x dựa trên act_name:
    'relu', 'sigmoid', hoặc 'elu'.
    """
    result = None
    if act_name == 'relu':
        result = calc_relu(x)

    elif act_name == 'sigmoid':
        result = calc_sig(x)

    elif act_name == 'elu':
        result = calc_elu(x)

    else:
        result = None

    return result

assert calc_activation_func(x = 1, act_name='relu') == 1

def interactive_activation_function():
    x = input('Input x = ')
    if not is_number(x):
        print('x must be a number')
        return # exit()

    act_name = input('Input activation function (sigmoid|relu|elu): ')
    x = float(x)
    result = calc_activation_func(x, act_name)
    if result is None:
        print(f'{act_name} is not supportted')
    else:
        print(f'{act_name}: f({x}) = {result}')
    return None

if __name__=="__main__":
    _ = interactive_activation_function()