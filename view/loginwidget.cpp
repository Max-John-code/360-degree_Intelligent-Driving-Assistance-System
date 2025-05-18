#include "loginwidget.h"
#include "ui_loginwidget.h"

LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
    //设置编辑框的正则限制
    QRegExp regExp1("[A-Za-z0-9]{6}");
    QValidator *validator1 = new QRegExpValidator(regExp1, ui->lineEdit);
    ui->lineEdit->setValidator(validator1);
    QRegExp regExp2("[A-Za-z0-9]{6,10}");
    QValidator *validator2 = new QRegExpValidator(regExp2, ui->lineEdit_2);
    ui->lineEdit_2->setValidator(validator2);
    QRegExp regExp3("[A-Za-z0-9]{4}");
    QValidator *validator3 = new QRegExpValidator(regExp3, ui->lineEdit_3);
    ui->lineEdit_3->setValidator(validator3);

    this->wth = WriteThread::getInstance();
    this->rth = ReadThread::getInstance();
    connect(this->rth, SIGNAL(loginSuccess(QString)), this, SLOT(toMainWidget(QString)), Qt::QueuedConnection);
    connect(this->rth, SIGNAL(loginFail()), this, SLOT(loginFail()));
    connect(this->rth, SIGNAL(heartLoss()), this, SLOT(hreatLoss()));

    // 设置随机数种子为当前时间的秒数
    qsrand(static_cast<uint>(QTime::currentTime().second()));
    //随机生成一个验证码 直接调用点击刷新验证码按钮刷新的槽函数
    this->on_pushButton_2_clicked();

    this->regwidget = new RegWidget;
    connect(this->regwidget, SIGNAL(backToLogin(QString)), this, SLOT(RegToLogin(QString)));
    connect(this->regwidget, SIGNAL(backToLogin2()), this, SLOT(RegToLogin2()));

}

LoginWidget::~LoginWidget()
{
    delete ui;
}
//MD5加密函数
QString LoginWidget::MD5Encryption(const QString &str)
{
    QCryptographicHash md5(QCryptographicHash::Md5);
    md5.addData(str.toLocal8Bit());
    qDebug() << md5.result().toHex();
    return md5.result().toHex();
}

void LoginWidget::Clear()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}

uint32_t crc32(const char *data, size_t size)
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

void LoginWidget::on_pushButton_3_clicked()
{
    this->regwidget->show();
    this->hide();
}

void LoginWidget::RegToLogin(QString userid)
{
    this->regwidget->close();
    ui->lineEdit->setText(userid);
    this->show();
}

void LoginWidget::RegToLogin2()
{
    this->regwidget->close();
    this->show();
}

void LoginWidget::loginFail()
{
    QMessageBox::warning(this, "登陆失败", "账号或密码错误");
    this->Clear();
    return ;
}

void LoginWidget::hreatLoss()
{
    QMessageBox::warning(this, "长时间未操作，已断开连接", "请重启程序");
    emit loginToSet();
}

void LoginWidget::on_pushButton_4_clicked()
{
    //编辑框为空的检测
    if(ui->lineEdit->text().isEmpty()||ui->lineEdit_2->text().isEmpty()||ui->lineEdit_3->text().isEmpty())
    {
        QMessageBox::warning(this, "登陆界面", "编辑框内容填写不完整");
        this->Clear();
        return ;
    }
    //验证码比较结果不对 大小写通用
    if(ui->lineEdit_3->text().toLower()!=ui->pushButton_2->text().toLower())
    {
        QMessageBox::warning(this, "登陆界面", "验证码错误");
        ui->lineEdit_3->clear();
        //刷新验证码
        this->on_pushButton_2_clicked();
        return ;
    }

    //登录的业务类型
    head.businessType = 3;
    head.businessLength = sizeof(LOGIN);
    //CRC
//    char *CRC;
//    memcpy(CRC, &login,  sizeof(login));
//    head.CRC = crc32(reinterpret_cast<char*>(&login),  sizeof(LOGIN));

    strcpy(login.user_account, ui->lineEdit->text().toStdString().c_str());
    strcpy(login.user_pwd, MD5Encryption(ui->lineEdit_2->text()).toStdString().c_str());
//    strcpy(login.user_pwd, ui->lineEdit_2->text().toStdString().c_str());

    //crc
//    char crcBuf[1000] = {0};
//    memcpy(crcBuf, &login, sizeof (LOGIN));
//    head.CRC = crc32(crcBuf, sizeof(LOGIN));
//    qDebug() << "head.CRC = " << head.CRC ;

    //自定义通信协议 头＋体
//    memcpy(buf, &head, sizeof(HEAD));
//    memcpy(buf + sizeof(HEAD), &login, sizeof(LOGIN));

    char bodyBuf[2000] = {0};
    memcpy(bodyBuf, &login, sizeof (LOGIN));
    this->wth->setData(head, bodyBuf);
}

void LoginWidget::toMainWidget(QString username)
{
    QMessageBox::information(this, "登陆界面", "登陆成功");

    //记录登录的用户名
    emit loginToMain(ui->lineEdit->text(), username);
    this->Clear();
}
//密码明密文切换
void LoginWidget::on_pushButton_clicked()
{
    ui->lineEdit_2->echoMode()==QLineEdit::Password?ui->lineEdit_2->setEchoMode(QLineEdit::Normal):ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

void LoginWidget::on_pushButton_2_clicked()
{
    //用一个字符串接收随机生成的验证码
        QString code;
        int num;
        code.clear();
        for(int i=0;i<4;++i){
            num = qrand()%3;//通过随机数决定生成数组、大写还是小写字母
            if(num==0)
            {
                //数字
                code += QString::number(qrand()%10);
            }
            else if(num==1)
            {
                //大写字母
                int temp = 'A';
                code += static_cast<QChar>(temp + qrand()%26);
            }
            else if(num==2)
            {
                //小写字母
                int temp = 'a';
                code += static_cast<QChar>(temp + qrand()%26);
            }
        }
        qDebug() << "code = " << code;
        //将按钮中的内容换成生成的验证码
        ui->pushButton_2->setText(code);
}

void LoginWidget::on_pushButton_5_clicked()
{
    //表单清除
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}

