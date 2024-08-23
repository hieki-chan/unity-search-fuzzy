using UnityEngine;
using Hieki.Search;

public class SampleUsage : MonoBehaviour
{
    void Start()
    {
        SampleTest();
    }

    public void SampleTest()
    {
        // TEST CASES
        Debug.Log("ratio :fuzzy search & fuzi serxh -> " + Fuzzy.Ratio("fuzzy search", "fuzi serxh"));
        Debug.Log("ratio: ths is the test & this is the test -> " + Fuzzy.Ratio("ths is the test", "this is the test", 3));
        Debug.Log("ratio: apple & apkhj -> " + Fuzzy.Ratio("apple", "apkhj"));
        Debug.Log("ratio: ana & banana ->" + Fuzzy.Ratio("ana", "banana"));
        Debug.Log("ratio: coconutt & coconut -> " + Fuzzy.Ratio("coconutt", "coconut"));
        Debug.Log("ratio: something went wrong & smthing go wrog -> " + Fuzzy.Ratio("something went wrong", "smthing go wrog"));
        Debug.Log("ratio: a & ab -> " + Fuzzy.Ratio("a", "ab"));
        Debug.Log("ratio: a & b -> " + Fuzzy.Ratio("a", "b"));
        Debug.Log("ratio: a & a -> " + Fuzzy.Ratio("a", "a"));
        Debug.Log("ratio: \"\" & ab -> " + Fuzzy.Ratio("", "ab"));
        Debug.Log("ratio: \"\" & sting.Empty -> " + Fuzzy.Ratio("", string.Empty));
    }
}
