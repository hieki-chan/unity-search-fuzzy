# Fuzzy-Search
Simple fuzzy search for unity

## How to use Fuzzy Search step by step

### Import Package

```
Window > Package Manager > (+) Plus Button > Add Package form git Url
```

git URL:

```
https://github.com/hieki-chan/unity-search-fuzzy.git
```

### Example

```C#
using Hieki.Search;

```

```C#
// Example
double ratio = Fuzzy.Ratio("something went wrong", "smthing go wrog");
Debug.Log(ratio);  // unity
-> 0.4516
```


```
you can try this out for more!
```
