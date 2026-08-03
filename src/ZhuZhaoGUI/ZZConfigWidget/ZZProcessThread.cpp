#include "ZZProcessThread.h"
#include "PhotometricStereo.h"
#include "ImageConvert.h"
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

ZZProcessThread::ZZProcessThread()
{

}

void ZZProcessThread::SetPhotometricStereoParams(QList<QImage>& srcImages,
                                QList<float>& Slants,
                                QList<float>& Tilts)
{
    m_srcImages.clear();
    m_Slants.clear();
    m_Tilts.clear();

    m_srcImages = srcImages;
    m_Slants = Slants;
    m_Tilts = Tilts;
}

void ZZProcessThread::GetResultImages(QList<QImage>& dstImages)
{
    dstImages = m_dstImages;
}

void ZZProcessThread::run()
{
    //准备输入数据和输出数据
    std::vector<cv::Mat> srcImages;
    std::vector<float> srcSlants;
    std::vector<float> srcTilts;
    cv::Mat dstHeightFieldImg;
    cv::Mat dstGradientImg;
    cv::Mat dstAlbedoImg;
    //先将输入参数整理为算法动态库接受的格式
    for(int i = 0; i < m_srcImages.size(); i++)
    {
        QImage qsrcImage = m_srcImages.at(i).convertToFormat(QImage::Format_Grayscale8);
        cv::Mat srcImage = QImage2cvMat(qsrcImage);
        srcImages.push_back(srcImage);
        srcSlants.push_back(m_Slants.at(i));
        srcTilts.push_back(m_Tilts.at(i));
    }

    //运行算法
    ZhuZhao::PhotometricStereo(srcImages,
                               dstHeightFieldImg,
                               dstGradientImg,
                               dstAlbedoImg,
                               srcImages.size(),
                               srcSlants,
                               srcTilts );

    //将算法结果转换并保存
    m_dstImages.clear();
    m_dstImages.push_back(cvMat2QImage(dstHeightFieldImg));
    m_dstImages.push_back(cvMat2QImage(dstGradientImg));
    m_dstImages.push_back(cvMat2QImage(dstAlbedoImg));
}
