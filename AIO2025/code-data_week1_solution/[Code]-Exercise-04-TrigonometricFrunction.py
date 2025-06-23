def factorial_fcn(x):
    """
    Compute the factorial of a non-negative integer x.

    Parameters:
    x (int): The input integer (x >= 0)

    Returns:
    int: The factorial of x (i.e., x!)
    """
    res = 1
    for i in range(x):
        res *= (i + 1)
    return res

def approx_sin(x, n):
    """
    Approximate the sine of x using the Taylor series expansion.

    Parameters:
    x (float): The input angle in radians.
    n (int): Number of terms in the Taylor series expansion.

    Returns:
    float: Approximate value of sin(x) using n+1 terms.
    """
    sin_approx = 0
    for i in range(n + 1):
        coef = (-1)**i
        num = x**(2 * i + 1)
        denom = factorial_fcn(2 * i + 1)
        sin_approx += coef * (num / denom)

    return sin_approx

def approx_cos(x, n):
    """
    Approximate the cosine of x using the Taylor series expansion.
    Parameters:
    x (float): The input angle in radians.
    n (int): Number of terms in the Taylor series expansion.
    Returns:
    float: Approximate value of cos(x) using n+1 terms.
    """
    cos_approx = 0
    for i in range(n + 1):
        coef = (-1) ** i
        num = x ** (2 * i)
        denom = factorial_fcn(2 * i)
        cos_approx += coef * (num / denom)

    return cos_approx

def approx_sinh(x, n):
    """
    Approximate the hyperbolic sine of x using the Taylor series expansion.
    Parameters:
    x (float): The input value.
    n (int): Number of terms in the Taylor series expansion.
    Returns:
    float: Approximate value of sinh(x) using n+1 terms.
    """

    sinh_approx = 0
    for i in range(n + 1):
        num = x ** (2 * i + 1)
        denom = factorial_fcn(2 * i + 1)
        sinh_approx += num / denom
    return sinh_approx

def approx_cosh(x, n):
    """
    Approximate the hyperbolic cosine of x using the Taylor series.
    Parameters:
    x (float): The input value.
    n (int): Number of terms in the Taylor series expansion.
    Returns:
    float: Approximate value of cosh(x) using n+1 terms.
    """
    cosh_approx = 0
    for i in range(n + 1):
        num = x ** (2 * i)
        denom = factorial_fcn(2 * i)
        cosh_approx += num / denom

    return cosh_approx

if __name__=="__main__":
    score = round(approx_cosh(x=1, n=10), 2)
    print(score)