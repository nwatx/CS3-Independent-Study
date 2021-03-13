import TutorialLayout from "../../components/TutorialLayout";
import fs from "fs";
import path from "path";
import matter from "gray-matter";
import { MDXProvider } from "@mdx-js/react";
import renderToString from "next-mdx-remote/render-to-string";
import hydrate from "next-mdx-remote/hydrate";
import Head from "next/head";
import Image from "next/image";
import imageMetadata from "../../plugins/image-metadata";

type FrontmatterProps = {
	title: string;
	description: string;
	date: Date | string;
};

const ImageLoader = ({ src, width }) => {
	return `https://ik.imagekit.io/nwatx/${src}?tr=w-${Math.min(1000, width)}`;
};

const MDXComponents = {
	img: (props) => {
		console.log(JSON.stringify(props));
		const { src, ...rest } = props;
		return (
			<div className="relative w-auto h-auto max-h-full">
				<div className="rounded-md">
					<Image
						className="rounded-lg"
						loader={ImageLoader}
						objectFit="contain"
						layout="responsive"
						width="100%"
						height="auto"
						src={src}
						{...rest}
					/>
				</div>
			</div>
		);
	},
};

const Post = ({ source, frontmatter }) => {
	const content = hydrate(source, { components: MDXComponents });

	const { title, description }: FrontmatterProps = frontmatter;

	console.log(frontmatter);

	return (
		<MDXProvider components={MDXComponents}>
			<Head>
				<title>{`Compete Tutorial - ${title}`}</title>
				<meta name="description" content={`${description || ""}`} />
			</Head>
			<TutorialLayout>{content}</TutorialLayout>
		</MDXProvider>
	);
};

export async function getStaticPaths() {
	const files = fs.readdirSync("content/tutorial");

	const paths = files.map((filename) => ({
		params: {
			slug: filename.replace(".mdx", ""),
		},
	}));

	return {
		paths,
		fallback: false,
	};
}

export async function getStaticProps({ params: { slug } }) {
	const markdownWithMetadata = fs
		.readFileSync(path.join("content/tutorial", slug + ".mdx"))
		.toString();

	const { data, content } = matter(markdownWithMetadata);

	const { date } = data as FrontmatterProps;

	// Convert post date to format: Month day, Year
	const options = { year: "numeric", month: "long", day: "numeric" };
	console.log(JSON.stringify(data), data.date, typeof data.date);
	// const dataWithDateFormattedToString = data;
	const formattedDate = date.toLocaleString(undefined, options);
	// dataWithDateFormattedToString['date'] = formattedDate;

	const source = await renderToString(content, {
		components: MDXComponents,
		scope: {},
		mdxOptions: { rehypePlugins: [imageMetadata] },
	});

	const frontmatter = {
		...data,
		date: formattedDate,
	};

	console.log("frontmatter", JSON.stringify(frontmatter));
	// console.log("source", JSON.stringify(source));

	return {
		props: {
			source,
			frontmatter,
		},
	};
}

export default Post;
