const functions = require("firebase-functions");
const admin = require("firebase-admin");
const nodemailer = require("nodemailer");

admin.initializeApp();

// Configure Nodemailer with Gmail (or use SendGrid/other SMTP)
const transporter = nodemailer.createTransport({
    service: "gmail",
    auth: {
        user: "yourgmail@gmail.com", // replace with your email
        pass: "your-app-password" // use Gmail App Password
    }
});

// Trigger when a user logs in
exports.sendLoginNotification = functions.auth.user().onLogin((user) => {
    const mailOptions = {
        from: "yourgmail@gmail.com",
        to: user.email,
        subject: "Login Attempt Notification",
        text: `Hello ${user.email},\n\nA login attempt was made to your account.\nIf this was not you, please reset your password immediately.\n\nSecure Student Document System`
    };

    return transporter.sendMail(mailOptions)
        .then(() => console.log("Login email sent to:", user.email))
        .catch((error) => console.error("Error sending email:", error));
});