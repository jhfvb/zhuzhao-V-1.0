#ifndef ZZONEPARAMWIDGET_H
#define ZZONEPARAMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QPushButton>

class ZZOneParamWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ZZOneParamWidget(QString paramName, QWidget *parent = nullptr);

    QImage GetQImage();
    void SetSlantAngle(float fSlant);
    float GetSlantAngle();
    void SetTiltAngle(float fTilt);
    float GetTiltAngle();
    void Reset();

protected:
    bool InitWidget();

protected slots:
    void OnSigLoadImageBtnClicked(bool clicked);

private:
    QString m_strParamName;
    QLabel* m_pTitleLabel;
    QLabel* m_pSlantsLabel;
    QDoubleSpinBox* m_pSlantsSpin;
    QLabel* m_pTiltsLabel;
    QDoubleSpinBox* m_pTiltsSpin;
    QPushButton* m_pLoadImageBtn;
    QImage m_qImage;
};

#endif // ZZONEPARAMWIDGET_H
