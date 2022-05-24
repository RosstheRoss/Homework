class BinaryVsLinear
{

  private static int linearSearch(int key, int[] keys)
  {
    int searchCount = 0;
    for (int i=0; i<keys.length; i+=1) {
      searchCount += 1;
      if (keys[i]==key) {
        return searchCount;
      }
    } return -1;
  }
  

  private static int binarySearch(int key, int[] keys)
  {
    int left=0; int right=(keys.length-1); int mid=0;
    int searchCount=0;
    while (true) {
      if (left>right) {
        mid=-1;
        break;
      } else {
        mid=(left+right)/2;
        searchCount += 2;
        if (key<keys[mid]) {
          right=mid-1;
        }
        else if (key>keys[mid]) {
          left=mid+1;
        } else {
          break;
        }
      }
    } return searchCount;
  }

  public static void main(String[] args)
  {
    for (int length = 1; length <= 30; length += 1)
    {
      int[] array = new int[length];
      for (int index = 0; index < length; index += 1)
      {
        array[index] = index;
      }

      double linearTotal = 0.0;
      double binaryTotal = 0.0;
      for (int element = 0; element < length; element += 1)
      {
        linearTotal += linearSearch(element, array);
        binaryTotal += binarySearch(element, array);
      }

      double linearAverage = linearTotal / length;
      double binaryAverage = binaryTotal / length;
      System.out.println(length + " " + linearAverage + " " + binaryAverage);
    }
  }
}
