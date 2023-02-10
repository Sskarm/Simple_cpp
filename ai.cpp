#include <opencv2/ml.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;
using namespace cv::ml;

int main(int argc, char** argv)
{
    // Load the data set
    auto data = ml::TrainData::loadFromCSV("data.csv", 0, -1, -1, String());

    // Split the data into training and testing sets
    auto trainData = data->getSubMat(0, 0, data->getNTrainSamples(), -1);
    auto testData = data->getSubMat(data->getNTrainSamples(), 0, data->getNTestSamples(), -1);

    // Define the machine learning algorithm
    auto kNearest = KNearest::create();

    // Train the machine learning algorithm with the training data
    kNearest->train(trainData);

    // Use the machine learning algorithm to predict the digits in the testing set
    Mat results, neighborResponses;
    float response;
    int accuracy = 0;
    for (int i = 0; i < testData.rows; ++i)
    {
        Mat sample = testData.row(i);
        kNearest->findNearest(sample, 1, results, neighborResponses, response);

        // Check if the prediction is correct
        if (results.at<float>(0, 0) == testData.at<float>(i, 0))
        {
            ++accuracy;
        }
    }

    // Calculate the accuracy of the predictions
    cout << "Accuracy: " << (float)accuracy / testData.rows * 100 << "%" << endl;

    return 0;
}
