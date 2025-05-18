#include "regwidget.h"
#include "ui_regwidget.h"

RegWidget::RegWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegWidget)
{
    ui->setupUi(this);
    //正则表达式对编辑框限制
    QRegExp regExp1("[A-Za-z0-9]{6}");
    QValidator *validator1 = new QRegExpValidator(regExp1, ui->lineEdit);
    ui->lineEdit->setValidator(validator1);
    QRegExp regExp2("[A-Za-z0-9]{6,8}");
    QValidator *validator2 = new QRegExpValidator(regExp2, ui->lineEdit_2);
    ui->lineEdit_2->setValidator(validator2);
    QRegExp regExp3("[A-Za-z0-9]{6,10}");
    QValidator *validator3 = new QRegExpValidator(regExp3, ui->lineEdit_3);
    ui->lineEdit_3->setValidator(validator3);
    QRegExp regExp4("[A-Za-z0-9]{6,10}");
    QValidator *validator4 = new QRegExpValidator(regExp4, ui->lineEdit_4);
    ui->lineEdit_4->setValidator(validator4);
    this->wth = WriteThread::getInstance();
    this->rth = ReadThread::getInstance();
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SIGNAL(backToLogin2()));
    connect(this->rth, SIGNAL(regSuccess()), this, SLOT(successToLogin()), Qt::QueuedConnection);
    connect(this->rth, SIGNAL(regFail()), this, SLOT(regFail()), Qt::QueuedConnection);
}

RegWidget::~RegWidget()
{
    delete ui;
}

QString RegWidget::MD5Encryption(const QString &str)
{
    QCryptographicHash md5(QCryptographicHash::Md5);
    md5.addData(str.toLocal8Bit());
    qDebug() << md5.result().toHex();
    return md5.result().toHex();
}

void RegWidget::Clear()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
}

uint32_t RegWidget::crc32(const char *data, size_t size)
{
    unsigned char i;
    uint32_t crc=POLY_INIT; /* 计算的初始crc值 */
    const uint32_t polynomial= POLYNOMIAL;

    while(size--)
    {
        crc ^= ((uint32_t)(*data++)<<24);
        for (i=8; i>0; --i)   /* 下面这段计算过程与计算一个字节crc一样 */
        {
            if (crc & 0x80000000)
                crc = (crc << 1) ^ polynomial;
            else
                crc = (crc << 1);
        }
    }
    crc=crc^POLY_END;
     return (crc);
}

void RegWidget::on_pushButton_clicked()
{
    //编辑框为空的检测
    if(ui->lineEdit->text().isEmpty()||ui->lineEdit_2->text().isEmpty()||ui->lineEdit_3->text().isEmpty()||ui->lineEdit_4->text().isEmpty())
    {
        QMessageBox::warning(this, "注册界面", "编辑框内容填写不完整");
        this->Clear();
        return ;
    }

    //两次密码输入不正确的检测
    if(ui->lineEdit_3->text()!=ui->lineEdit_4->text())
    {
        QMessageBox::warning(this, "注册界面", "两次密码输入不一致");
        this->Clear();
        return ;
    }
    //注册的业务类型
    head.businessType = 1;
    head.businessLength = sizeof(REG);
//    head.CRC = crc32(reinterpret_cast<char*>(&reg),  sizeof(REG));

    strcpy(reg.user_account, ui->lineEdit->text().toStdString().c_str());
    strcpy(reg.user_name, ui->lineEdit_2->text().toStdString().c_str());
    strcpy(reg.user_pwd, MD5Encryption(ui->lineEdit_3->text()).toStdString().c_str());
    qDebug() << "reg.user_pwd = " << reg.user_pwd ;
    //CRC
//    char crcBuf[1000] = {0};
//    memcpy(crcBuf, &reg, sizeof (REG));
//    qDebug() << "crcBuf = " << crcBuf;
//    qDebug() << "sizeof(REG) = " << sizeof (REG);
//    head.CRC = crc32(crcBuf, sizeof(REG));
//    qDebug() << "CRC = " << head.CRC;

    //自定义通信协议 头＋体
//    memcpy(buf, &head, sizeof(HEAD));
//    memcpy(buf + sizeof(HEAD), &reg, sizeof(REG));

    char bodyBuf[2000] = {0};
    memcpy(bodyBuf, &reg, sizeof (REG));

    this->wth->setData(head, bodyBuf);
}

void RegWidget::successToLogin()
{
    QMessageBox::information(this, "注册界面", "注册成功");
    emit this->backToLogin(ui->lineEdit->text());
    this->Clear();
}

void RegWidget::regFail()
{
    QMessageBox::warning(this, "注册失败", "用户账号已存在");
    this->Clear();
    return ;
}
