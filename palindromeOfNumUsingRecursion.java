class palindromeOfNumUsingRecursion{
    static boolean isPalindrome = true;
    public static void main(String[] args) {
        int num = 13341;
        palindrome(num);
        System.out.println(isPalindrome);
    }
    static boolean palindrome(int n) {
        int digits = (int) Math.log10(n);
        int decDigits = (int) Math.pow(10, digits);

        if(!isPalindrome){
            return isPalindrome = false;
        }
        if (n / decDigits == n % 10) {
            if((n % decDigits)!=0){
                palindrome((n % decDigits) / 10);
            }
        } else {
            return isPalindrome = false;
        }
        return false;
    }
}
