import {
    Alert,
    AlertDescription,
    AlertIcon,
    AlertTitle,
    Button,
    Center,
    Input,
    Link,
    Text,
} from "@chakra-ui/react";
import { useContext, useState } from "react";
import { FcGoogle } from "react-icons/fc";
import DefaultLayout from "../../components/DefaultLayout";
import UserProvider, {
    useUser,
    UseUserInterface,
} from "../../context/UserProvider";

const Login = () => {
    const {
        signInGoogle,
        signInEmailPassword,
        error,
        router,
    }: UseUserInterface = useUser();
    const [email, setEmail] = useState("");
    const [password, setPassword] = useState("");

    const filledOutForm: boolean = Boolean(password && email);

    return (
        <DefaultLayout>
            <div className="flex min-h-screen w-full h-full justify-center bg-gray-50">
                <div className="flex w-full h-auto md:h-2/3 sm:w-full lg:max-w-1/2 xl:max-w-1/3 bg-gray-50 self-center rounded-lg flex-col shadow-lg">
                    <div className="mx-3 lg:mx-8 my-auto mt-10 h-auto">
                        <div className="flex mx-3 my-3">
                            <p className="text-3xl text-gray-700 w-full font-bold">
                                Login to{" "}
                                <b className="bg-clip-text text-transparent bg-gradient-to-tr font-extrabold from-red-400 to-pink-800">
                                    Compete
                                </b>
                            </p>
                        </div>
                        <div className="flex mx-4 my-3 flex-col">
                            <div className="flex w-full my-3">
                                <p className="text-md font-medium text-gray-800">
                                    Email
                                </p>
                            </div>
                            <div className="flex w-full">
                                <Input
                                    onChange={(e) => setEmail(e.target.value)}
                                />
                            </div>
                        </div>
                        <div className="flex mx-4 my-3 flex-col">
                            <div className="flex w-full my-3">
                                <p className="text-md font-medium text-gray-800">
                                    Password
                                </p>
                            </div>
                            <div className="flex w-full">
                                <Input
                                    type="password"
                                    onChange={(e) =>
                                        setPassword(e.target.value)
                                    }
                                />
                            </div>
                        </div>
                        <div className="flex h-auto" />
                        <div className="flex mx-4 my-3">
                            <button
                                onClick={() =>
                                    signInEmailPassword(email, password)
                                }
                                className={`flex h-full w-full bg-gray-300 py-2 rounded-md text-center justify-center ${
                                    filledOutForm
                                        ? "bg-gray-800"
                                        : "cursor-default"
                                }`}
                                disabled={!filledOutForm}
                            >
                                <p className="text-lg font-medium text-white text-center">
                                    Create Account
                                </p>
                            </button>
                        </div>
                        <div className="flex mx-4 my-3 w-auto">
                            <Button
                                w={"full"}
                                variant={"outline"}
                                leftIcon={<FcGoogle />}
                                onClick={() => signInGoogle(false)}
                            >
                                <Center>
                                    <Text>Sign up with Google</Text>
                                </Center>
                            </Button>
                        </div>
                        <div
                            className={`flex mx-4 my-5 ${
                                !error && "mb-10"
                            } w-auto text-center justify-center`}
                        >
                            <p>
                                Don't have an account?{" "}
                                <Link
                                    onClick={() => {
                                        router.push("/user/signup");
                                    }}
                                >
                                    Sign Up
                                </Link>
                            </p>
                        </div>
                        {error && (
                            <div className="flex mx-4 my-3 mb-10 w-auto rounded-sm">
                                <Alert rounded="md" status="error">
                                    <AlertIcon />
                                    <AlertTitle mr={2}>
                                        Registration error:
                                    </AlertTitle>
                                    <AlertDescription>{error}</AlertDescription>
                                </Alert>
                            </div>
                        )}
                    </div>
                </div>
            </div>
        </DefaultLayout>
    );
};

export default Login;
