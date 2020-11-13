const functions = require('firebase-functions');
// // Create and Deploy Your First Cloud Functions
// // https://firebase.google.com/docs/functions/write-firebase-functions
//

const express = require('express');
const app = express();

const FBAuth = require('./util/fbAuth')

const { getAllScreams, postOneScream } = require('./handlers/screams');
const { signup, login, uploadImage } = require('./handlers/users');

app.get('/screams', getAllScreams);
app.post('/scream', FBAuth, postOneScream)

app.post('/signup', signup);
app.post('/login', login);
app.post('/user/image', FBAuth, uploadImage)

exports.api = functions.https.onRequest(app);