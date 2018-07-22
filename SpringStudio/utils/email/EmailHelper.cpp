#include "EmailHelper.h"

#include <QDebug>

#include "sender.h"

#include "mimetext.h"

using namespace SimpleMail;

EmailHelper::EmailHelper()
{

}

EmailHelper::SendEmailResult EmailHelper::sendEmail_QQ(QString senderAddr, QString password, QString receiverAddr, QString subject, QString content)
{
    SimpleMail::Sender smtp(QLatin1String("smtp.qq.com"), 465, Sender::SslConnection);
    smtp.setUser(senderAddr);
    smtp.setPassword(password);

    EmailAddress sender(senderAddr, senderAddr);
    EmailAddress to(receiverAddr, receiverAddr);

    MimeMessage message;
    message.setSender(sender);
    message.addTo(to);
    message.setSubject(subject);

    // email content
    MimeText text;
    text.setText(content);
    message.addPart(&text);

    EmailHelper::SendEmailResult r;

    if (!smtp.sendMail(message)) {
        r.success = false;
        r.errorTip = smtp.lastError();
    }else{
        r.success = true;
    }

    smtp.quit();
    return r;
}
