#ifndef EMAILHELPER_H
#define EMAILHELPER_H

#include <QString>

class EmailHelper
{
public:
    EmailHelper();

    class SendEmailResult
    {
    public:
        SendEmailResult(){
            success = true;
            errorTip = "";
        }
        bool success;
        QString errorTip;
    };

    //! 使用QQ邮箱发送邮件
    SendEmailResult sendEmail_QQ(QString senderAddr,
                   QString password,
                   QString receiverAddr,
                   QString subject = "",
                   QString content = "");


};

#endif // EMAILHELPER_H
