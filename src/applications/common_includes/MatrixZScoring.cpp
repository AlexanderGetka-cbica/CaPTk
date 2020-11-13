
#include "MatrixZScoring.h"

namespace ZScoring
{

void ZScoreNormalizeByColumns(cv::Mat featureMatrix, cv::Mat& output)
{
	int rows = featureMatrix.rows;
	int cols = featureMatrix.cols;

	//cv::Mat zscores(rows, 1, CV_64F); // set up zscore mat so it doesn't get scope-destructed

	for (int i = 0; i < cols; i++)
	{
		cv::Mat thisCol = featureMatrix.col(i);
		cv::Scalar meanValue, stdValue;

		//cv::randn(thisCol, 10000, 500); // Remove this, just for testing
		// read into meanValue, stdValue
		cv::meanStdDev(thisCol, meanValue, stdValue);

		double colMean = meanValue[0];
		double colStdDev = stdValue[0];

		cv::Mat zscores(rows, 1, CV_64F);
		zscores = (thisCol - colMean) / (colStdDev); // all should be element-wise

		//cv::Mat zTmp = thisCol - colMean;
		//cv::divide(colStdDev, zTmp, zscores); // divide zTmp by colStdDev
		//cv::Mat temp = zscores.col(0).clone();
		zscores.col(0).copyTo(output.col(i));

	}

}


	/*
		double colMean = cv::mean(col).val[0]; //.val[0] gets value of single-value cv::Scalar
		double colSum = cv::sum(col).val[0];



		// calculate standard deviation
		cv::Mat temp = col - colMean; // deviations
		temp = temp.mul(temp); // squared
		double colVariance = (cv::sum,(temp).val[0]) / (rows - 1.0);
		double colStdDev = std::sqrt(colVariance)


		cv::Mat
	*/
}