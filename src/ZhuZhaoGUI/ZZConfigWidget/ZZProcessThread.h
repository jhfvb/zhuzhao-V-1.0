#ifndef ZZ_PROCESSTHREAD_H
#define ZZ_PROCESSTHREAD_H

#include <QThread>
#include <QImage>

class ZZProcessThread : public QThread
{
public:
    ZZProcessThread();
    //设置输入参数
    void SetPhotometricStereoParams(QList<QImage>& srcImages,
                                    QList<float>& Slants,
                                    QList<float>& Tilts);
    //获取算法的运行结果
    void GetResultImages(QList<QImage>& dstImages);

protected:
    void run() override;
private:
    volatile bool m_bIsStop;
    QList<QImage> m_srcImages;
    QList<QImage> m_dstImages;
    QList<float> m_Slants;
    QList<float> m_Tilts;
};

#endif // ZZ_PROCESSTHREAD_H
