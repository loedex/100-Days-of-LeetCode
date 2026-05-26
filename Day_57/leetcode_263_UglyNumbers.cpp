// Ugly numbers must be positive
        if (n <= 0) return false;
        
        // Repeatedly divide by 2, 3, and 5
        int factors[] = {2, 3, 5};
        for (int f : factors) {
            while (n % f == 0) {
                n /= f;
            }
        }
        
        // If n becomes 1, it's an ugly number
        return n == 1;