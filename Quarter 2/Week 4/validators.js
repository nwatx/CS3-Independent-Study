
const isEmpty = (string) => {
    return (string.trim() === '');
}

const isEmail = (email) => {
    const regEx = /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
    return (email.match(regEx));
}

exports.validateSignupData = (data) => {
    let errors = {};

    if(isEmpty(data.email)) { errors.email = 'Must not be empty'; }
    else if(!isEmail(data.email)) { errors.email = 'Must be a valid email address'; }

    //console.log(`dp: ${data.password} cp: ${data.confirmPassword}, ${data.password !== data.confirmPassword}`)

    if(isEmpty(data.password)) { errors.password = 'Must not be empty'; }
    if(data.password !== data.confirmPassword) { errors.confirmPassword = 'Password must match'; }

    if(isEmpty(data.handle)) { errors.handle = 'Must not be empty'; }

    return {
        errors, valid: Object.keys(errors).length === 0 ? true : false
    }
}

exports.validateLoginData = (data) => {
    let errors = {};
  
    if (isEmpty(data.email)) errors.email = 'Must not be empty';
    if (isEmpty(data.password)) errors.password = 'Must not be empty';
  
    return {
      errors,
      valid: Object.keys(errors).length === 0 ? true : false
    };
  };
  