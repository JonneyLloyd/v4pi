#include <alpr.h>

int main()
{

// Initialize the library using United States-style license plates.
// You can use other countries/regions as well (for example: "eu", "au", or "kr").
alpr::Alpr openalpr("eu", "/home/pi/openalpr/src/build/config/openalpr.conf");

// Optionally, you can specify the top N possible plates to return (with confidences). The default is ten.
openalpr.setTopN(20);

// Optionally, you can provide the library with a region for pattern matching. This improves accuracy by
// comparing the plate text with the regional pattern.
// openalpr.setDefaultRegion("md");

// Make sure the library loads before continuing.
// For example, it could fail if the config/runtime_data is not found.
if (openalpr.isLoaded() == false)
{
    std::cerr << "Error loading OpenALPR" << std::endl;
    return 1;
}

// Recognize an image file. Alternatively, you could provide the image bytes in-memory.
alpr::AlprResults results = openalpr.recognize("/home/pi/openalpr/src/build/lp.jpg");

// Carefully observe the results. There may be multiple plates in an image,
// and each plate returns the top N candidates.
for (int i = 0; i < results.plates.size(); i++)
{
  alpr::AlprPlateResult plate = results.plates[i];
  std::cout << "plate" << i << ": " << plate.topNPlates.size() << " results" << std::endl;

    for (int k = 0; k < plate.topNPlates.size(); k++)
    {
      alpr::AlprPlate candidate = plate.topNPlates[k];
      std::cout << "    - " << candidate.characters << "\t confidence: " << candidate.overall_confidence;
      std::cout << "\t pattern_match: " << candidate.matches_template << std::endl;
    }
}
return 0;
}
