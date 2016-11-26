class BinarySearch {
    static int binarySearch(int arr[], int left, int right, int k) {
        if (right > 1) {
            int mid = (left + (right - 1) )/2;
            if (arr[mid] == k) {
                return mid;
            }
            else if (arr[mid] > k) {
                return binarySearch(arr, left, mid, k);
            }
            else if (arr[mid] < k) {
                return binarySearch(arr, mid, right, k);
            }
        }
        return -1;
    }

    public static void main(String args[]) {
        int arr[] = {1, 11, 12, 31, 41};
        int left = 0;
        int right = arr.length - 1;
        int find = 11;
        int index = binarySearch(arr, left, right, find);
        System.out.println(index);
    }
}
