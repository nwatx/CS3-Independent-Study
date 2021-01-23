import "../styles/globals.css";
import { ChakraProvider } from "@chakra-ui/react";
import Head from "next/head";

function MyApp({ Component, pageProps }) {
    return (
        <>
            <Head>
                <title>QuadForm Calculator</title>
            </Head>
            <ChakraProvider>
                <Component {...pageProps} />
            </ChakraProvider>
        </>
    );
}

export default MyApp;
