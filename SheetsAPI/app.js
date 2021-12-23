import nodemailer from './node_modules/nodemailer';
import { google } from './node_modules/googleapis';

// These id's and secrets should come from .env file.
const CLIENT_ID = '332182818713-eg8oh6ugkfm3jblst55b36dt17f3k2rq.apps.googleusercontent.com';
const CLEINT_SECRET = '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';
const REDIRECT_URI = 'https://developers.google.com/oauthplayground';
const REFRESH_TOKEN = '1//04utx6f2E4ezbCgYIARAAGAQSNwF-L9IrOOrc3gqo6MptmMKQwlg7s4mD8lEIyBnYdNpE9RlYAYj8jWk7rNOsuKE6ffo1g4AHFBg';

const oAuth2Client = new google.auth.OAuth2(
  CLIENT_ID,
  CLEINT_SECRET,
  REDIRECT_URI
);
oAuth2Client.setCredentials({ refresh_token: REFRESH_TOKEN });

async function sendMail() {
  try {
    const accessToken = await oAuth2Client.getAccessToken();

    const transport = nodemailer.createTransport({
      service: 'gmail',
      auth: {
        type: 'OAuth2',
        user: 'wurtzreaxnwittigreaxn@gmail.com',
        clientId: CLIENT_ID,
        clientSecret: CLEINT_SECRET,
        refreshToken: REFRESH_TOKEN,
        accessToken: accessToken,
      },
    });

    const mailOptions = {
      from: '8100 Shubham Shrikant Bawner<wurtzreaxnwittigreaxn@gmail.com>',
      to: 'shreebawner@gmail.com',
      subject: 'Hello from gmail using API',
      text: 'Hello from gmail email using API',
      html: '<h1>Hello from gmail email using API</h1>',
    };

    const result = await transport.sendMail(mailOptions);
    return result;
  } catch (error) {
    return error;
  }
}

sendMail()
  .then((result) => console.log('Email sent...', result))
  .catch((error) => console.log(error.message));

console.log("swdeasd")