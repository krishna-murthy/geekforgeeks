class LinearSearch {

    static int search (int arr[], int n, int x) {
        for (int i = 0; i < n; i++) {
            if (x == arr[i]) {
                return 1;
            }
        }
        return -1;
    }

    public static void main(String args[]) {
        int n = 5;
        int arr[] = {3,4,5,1,2};
        int present = search(arr, arr.length, 40);
        if (present == 1) {
            System.out.println("found");
        }
        else {
            System.out.println("not found");
        }
    }
}
