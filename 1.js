/* ----------------- input ----------------- */
let user = {
    name: "Tony",
    address: {
    personal: {
    city: "Mumbai",
    area: "Robin Street"
    },
    office: {
    city: "Stark Tech Park",
    area: {
    landmark: "Avenge treet"
    }
    }
    }
    };

console.log("user_address_office_area_landmark:",user.address.office.area.landmark);
console.log("user_address_office_city:",user.address.office.city);
console.log("user_address_personal_area:",user.address.personal.area);
console.log("user_address_personal_city:",user.address.personal.city);
console.log("user_name:",user.name);
    