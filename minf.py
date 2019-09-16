import doctest
def prime(limit):
    """
            function for prime number sieves

            >>> [x for x in prime(10)]
            [2, 3, 5, 7]
    """
    sieve = [False]*limit
    for j in range(2, limit):
        if sieve[j]:
            continue
        yield j
        if j * j > limit: #optimization
            continue
        for i in range(j, limit, j):
            sieve[i] = True


if __name__ == "__main__":
    doctest.testmod()
    