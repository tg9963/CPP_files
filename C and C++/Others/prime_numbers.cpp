boolean isPrime(int number) {
    //check if number is 2, the odd even prime
    if (Math.abs(number) == 2)
        return true;
    //check if number is a multiple of 2
    if (number % 2 == 0)
        return false;
    //if not, then just check by dividing odd numbers. 
    //Starting from 3 till i < square root of number 
    // i.e.  i*i < number

    for (int i = 3; i * i <= number; i += 2) {
        if (number % i == 0)
            return false;
    }
    return true;
}
